/* -*- c++ -*- */
/*
 * Copyright 2005-2011,2013 Free Software Foundation, Inc.
 * Copyright 2021 Marcus Müller
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_GR_THROTTLE_H
#define INCLUDED_GR_THROTTLE_H

#include <gnuradio/blocks/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace blocks {

/*!
 * \brief throttle flow of samples such that the average rate does
 * not exceed samples_per_sec.
 * \ingroup misc_blk
 *
 * \details
 * input: one stream of itemsize; output: one stream of itemsize
 *
 * N.B. this should only be used in GUI apps where there is no
 * other rate limiting block. It is not intended nor effective at
 * precisely controlling the rate of samples. That should be
 * controlled by a source or sink tied to sample clock. E.g., a
 * USRP or audio card.
 *
 * You can insert this block "in series" with your sample flow, in which case it  does a
 * throttled copy of input to output. Alternatively, you can not connect its output and
 * just connect this block's input in parallel to an existing block in your flow graph. In
 * that case, Throttle will limit the rate at which samples are consumed; especially at
 * higher rates, where the copying overhead might be significant, this is functionally not
 * different to copying at a limited rate.
 */
class BLOCKS_API throttle : virtual public sync_block
{
public:
    typedef std::shared_ptr<throttle> sptr;

    static sptr make(size_t itemsize, double samples_per_sec, bool ignore_tags = true);

    //! Sets the sample rate in samples per second.
    virtual void set_sample_rate(double rate) = 0;

    //! Get the sample rate in samples per second.
    virtual double sample_rate() const = 0;
};

} /* namespace blocks */
} /* namespace gr */

#endif /* INCLUDED_GR_THROTTLE_H */
