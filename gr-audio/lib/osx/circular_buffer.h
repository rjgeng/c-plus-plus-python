/* -*- c++ -*- */
/*
 * Copyright 2006,2009,2010,2014 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef _CIRCULAR_BUFFER_H_
#define _CIRCULAR_BUFFER_H_

#include <gnuradio/logger.h>
#include <gnuradio/thread/thread.h>
#include <stdexcept>

#ifndef DO_DEBUG
#define DO_DEBUG 0
#endif

template <class T>
class circular_buffer
{
private:
    // the buffer to use
    T* d_buffer;

    // the following are in Items (type T)
    size_t d_bufLen_I, d_readNdx_I, d_writeNdx_I;
    size_t d_n_avail_write_I, d_n_avail_read_I;

    // stuff to control access to class internals
    gr::thread::mutex* d_internal;
    gr::thread::condition_variable* d_readBlock;
    gr::thread::condition_variable* d_writeBlock;

    // booleans to decide how to control reading, writing, and aborting
    bool d_doWriteBlock, d_doFullRead, d_doAbort;

    void delete_mutex_cond()
    {
        if (d_internal) {
            delete d_internal;
            d_internal = NULL;
        }
        if (d_readBlock) {
            delete d_readBlock;
            d_readBlock = NULL;
        }
        if (d_writeBlock) {
            delete d_writeBlock;
            d_writeBlock = NULL;
        }
    };

public:
    gr::logger_ptr d_logger, d_debug_logger;

    circular_buffer(size_t bufLen_I, bool doWriteBlock = true, bool doFullRead = false)
    {
        if (bufLen_I == 0)
            throw std::runtime_error("circular_buffer(): "
                                     "Number of items to buffer must be > 0.");
        d_bufLen_I = bufLen_I;
        d_buffer = (T*)new T[d_bufLen_I];
        d_doWriteBlock = doWriteBlock;
        d_doFullRead = doFullRead;
        d_internal = NULL;
        d_readBlock = d_writeBlock = NULL;
        reset();
        gr::configure_default_loggers(d_logger, d_debug_logger, "circular_buffer");
#if DO_DEBUG
        d_debug_logger->info(
            "c_b(): buf len (items) = {:d}, doWriteBlock = {:s}, doFullRead = {:s}",
            d_bufLen_I,
            d_doWriteBlock ? "true" : "false",
            d_doFullRead ? "true" : "false");
#endif
    };

    ~circular_buffer()
    {
        delete_mutex_cond();
        delete[] d_buffer;
    };

    inline size_t n_avail_write_items()
    {
        gr::thread::scoped_lock l(*d_internal);
        size_t retVal = d_n_avail_write_I;
        return (retVal);
    };

    inline size_t n_avail_read_items()
    {
        gr::thread::scoped_lock l(*d_internal);
        size_t retVal = d_n_avail_read_I;
        return (retVal);
    };

    inline size_t buffer_length_items() { return (d_bufLen_I); };
    inline bool do_write_block() { return (d_doWriteBlock); };
    inline bool do_full_read() { return (d_doFullRead); };

    void reset()
    {
        d_doAbort = false;
        bzero(d_buffer, d_bufLen_I * sizeof(T));
        d_readNdx_I = d_writeNdx_I = d_n_avail_read_I = 0;
        d_n_avail_write_I = d_bufLen_I;
        delete_mutex_cond();
        // create a mutex to handle contention of shared resources;
        // any routine needed access to shared resources uses lock()
        // before doing anything, then unlock() when finished.
        d_internal = new gr::thread::mutex();
        // link the internal mutex to the read and write conditions;
        // when wait() is called, the internal mutex will automatically
        // be unlock()'ed.  Upon return (from a notify_one() to the condition),
        // the internal mutex will be lock()'ed.
        d_readBlock = new gr::thread::condition_variable();
        d_writeBlock = new gr::thread::condition_variable();
    };

    /*
     * enqueue: add the given buffer of item-length to the queue,
     *     first-in-first-out (FIFO).
     *
     * inputs:
     *     buf: a pointer to the buffer holding the data
     *
     *     bufLen_I: the buffer length in items (of the instantiated type)
     *
     * returns:
     *    -1: on overflow (write is not blocking, and data is being
     *                     written faster than it is being read)
     *     0: if nothing to do (0 length buffer)
     *     1: if success
     *     2: in the process of aborting, do doing nothing
     *
     * will throw runtime errors if inputs are improper:
     *     buffer pointer is NULL
     *     buffer length is larger than the instantiated buffer length
     */

    int enqueue(T* buf, size_t bufLen_I)
    {
#if DO_DEBUG
        d_debug_logger->info(
            "enqueue: buf = {:p}, bufLen = {:d}, #av_wr = {:d}, #av_rd = {:d}",
            (void*)buf,
            bufLen_I,
            d_n_avail_write_I,
            d_n_avail_read_I);
#endif
        if (bufLen_I > d_bufLen_I) {
            d_debug_logger->info(
                "cannot add buffer longer ({:d}) than instantiated length ({:d}).",
                bufLen_I,
                d_bufLen_I);
            throw std::runtime_error("circular_buffer::enqueue()");
        }

        if (bufLen_I == 0)
            return (0);
        if (!buf)
            throw std::runtime_error("circular_buffer::enqueue(): "
                                     "input buffer is NULL.");
        gr::thread::scoped_lock l(*d_internal);
        if (d_doAbort) {
            return (2);
        }
        // set the return value to 1: success; change if needed
        int retval = 1;
        if (bufLen_I > d_n_avail_write_I) {
            if (d_doWriteBlock) {
                while (bufLen_I > d_n_avail_write_I) {
#if DO_DEBUG
                    d_debug_logger->info("enqueue #len > #a, waiting");
#endif
                    // wait; will automatically unlock() the internal mutex via
                    // the scoped lock
                    d_writeBlock->wait(l);
                    // and auto re-lock() it here.
                    if (d_doAbort) {
#if DO_DEBUG
                        d_debug_logger->info("enqueue #len > #a, aborting");
#endif
                        return (2);
                    }
#if DO_DEBUG
                    d_debug_logger->info("enqueue #len > #a, done waiting");
#endif
                }
            } else {
                d_n_avail_read_I = d_bufLen_I - bufLen_I;
                d_n_avail_write_I = bufLen_I;
#if DO_DEBUG
                d_logger->error("enqueue overflow");
#endif
                retval = -1;
            }
        }
        size_t n_now_I = d_bufLen_I - d_writeNdx_I, n_start_I = 0;
        if (n_now_I > bufLen_I)
            n_now_I = bufLen_I;
        else if (n_now_I < bufLen_I)
            n_start_I = bufLen_I - n_now_I;
        memcpy(&(d_buffer[d_writeNdx_I]), buf, n_now_I * sizeof(T));
        if (n_start_I) {
            memcpy(d_buffer, &(buf[n_now_I]), n_start_I * sizeof(T));
            d_writeNdx_I = n_start_I;
        } else
            d_writeNdx_I += n_now_I;
        d_n_avail_read_I += bufLen_I;
        d_n_avail_write_I -= bufLen_I;
        d_readBlock->notify_one();
        return (retval);
    };

    /*
     * dequeue: removes from the queue the number of items requested, or
     *     available, into the given buffer on a FIFO basis.
     *
     * inputs:
     *     buf: a pointer to the buffer into which to copy the data
     *
     *     bufLen_I: pointer to the requested number of items to remove
     *
     * outputs:
     *     bufLen_I: pointer to the actual number of items removed
     *
     * returns:
     *     0: if nothing to do (0 length buffer)
     *     1: if success
     *     2: in the process of aborting, do doing nothing
     *     3: if the number of requested items to remove is not the same
     *        as the actual number of items removed.
     *
     * will throw runtime errors if inputs are improper:
     *     buffer pointer is NULL
     *     buffer length pointer is NULL
     *     buffer length is larger than the instantiated buffer length
     */

    int dequeue(T* buf, size_t* bufLen_I)
    {
#if DO_DEBUG
        d_debug_logger->info(
            "dequeue: buf = {:p}, *bufLen = {:d}, #av_wr = {:d}, #av_rd = {:d}",
            (void*)buf,
            *bufLen_I,
            d_n_avail_write_I,
            d_n_avail_read_I);
#endif
        if (!bufLen_I)
            throw std::runtime_error("circular_buffer::dequeue(): "
                                     "input bufLen pointer is NULL.");
        if (!buf)
            throw std::runtime_error("circular_buffer::dequeue(): "
                                     "input buffer pointer is NULL.");
        size_t l_bufLen_I = *bufLen_I;
        if (l_bufLen_I == 0)
            return (0);
        if (l_bufLen_I > d_bufLen_I) {
            d_logger->error(
                "cannot remove buffer longer ({:d}) than instantiated length ({:d}).",
                l_bufLen_I,
                d_bufLen_I);
            throw std::runtime_error("circular_buffer::dequeue()");
        }

        gr::thread::scoped_lock l(*d_internal);
        if (d_doAbort) {
            return (2);
        }
        if (d_doFullRead) {
            while (d_n_avail_read_I < l_bufLen_I) {
#if DO_DEBUG
                d_debug_logger->info("dequeue #a < #len, waiting");
#endif
                // wait; will automatically unlock() the internal mutex via
                // the scoped lock
                d_readBlock->wait(l);
                // and re-lock() it here.
                if (d_doAbort) {
#if DO_DEBUG
                    d_debug_logger->info("dequeue #a < #len, aborting");
#endif
                    return (2);
                }
#if DO_DEBUG
                d_debug_logger->info("dequeue #a < #len, done waiting");
#endif
            }
        } else {
            while (d_n_avail_read_I == 0) {
#if DO_DEBUG
                d_debug_logger->info("dequeue: #a == 0, waiting.");
#endif
                // wait; will automatically unlock() the internal mutex via
                // the scoped lock
                d_readBlock->wait(l);
                // and re-lock() it here.
                if (d_doAbort) {
#if DO_DEBUG
                    d_debug_logger->info("dequeue: #a == 0, aborting.");
#endif
                    return (2);
                }
#if DO_DEBUG
                d_debug_logger->info("dequeue: #a == 0, done waiting.");
#endif
            }
        }
        if (l_bufLen_I > d_n_avail_read_I)
            l_bufLen_I = d_n_avail_read_I;
        size_t n_now_I = d_bufLen_I - d_readNdx_I, n_start_I = 0;
        if (n_now_I > l_bufLen_I)
            n_now_I = l_bufLen_I;
        else if (n_now_I < l_bufLen_I)
            n_start_I = l_bufLen_I - n_now_I;
        memcpy(buf, &(d_buffer[d_readNdx_I]), n_now_I * sizeof(T));
        if (n_start_I) {
            memcpy(&(buf[n_now_I]), d_buffer, n_start_I * sizeof(T));
            d_readNdx_I = n_start_I;
        } else
            d_readNdx_I += n_now_I;
        int rv = 1;
        if (*bufLen_I != l_bufLen_I)
            rv = 3;
        *bufLen_I = l_bufLen_I;
        d_n_avail_read_I -= l_bufLen_I;
        d_n_avail_write_I += l_bufLen_I;
        d_writeBlock->notify_one();
        return (rv);
    };

    void abort()
    {
        gr::thread::scoped_lock l(*d_internal);
        d_doAbort = true;
        d_writeBlock->notify_one();
        d_readBlock->notify_one();
    };
};

#endif /* _CIRCULAR_BUFFER_H_ */
