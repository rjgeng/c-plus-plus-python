/* -*- c++ -*- */
/*
 * Copyright 2008,2009,2011,2012,2014 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_QTGUI_SINK_F_IMPL_H
#define INCLUDED_QTGUI_SINK_F_IMPL_H

#include <gnuradio/qtgui/sink_f.h>

#include <gnuradio/fft/fft.h>
#include <gnuradio/fft/window.h>
#include <gnuradio/filter/firdes.h>
#include <gnuradio/high_res_timer.h>
#include <gnuradio/qtgui/SpectrumGUIClass.h>

namespace gr {
namespace qtgui {

class QTGUI_API sink_f_impl : public sink_f
{
private:
    void forecast(int noutput_items, gr_vector_int& ninput_items_required) override;

    void initialize();

    int d_fftsize;
    fft::window::win_type d_wintype;
    std::vector<float> d_window;
    double d_center_freq;
    double d_bandwidth;
    const std::string d_name;

    const pmt::pmt_t d_port;

    // Perform fftshift operation;
    // this is usually desired when plotting
    std::unique_ptr<fft::fft_complex_fwd> d_fft;

    int d_index = 0;
    volk::vector<float> d_residbuf;
    volk::vector<float> d_magbuf;

    bool d_plotfreq, d_plotwaterfall, d_plottime, d_plotconst;

    double d_update_time;

    // Required now for Qt; argc must be greater than 0 and argv
    // must have at least one valid character. Must be valid through
    // life of the qApplication:
    // http://harmattan-dev.nokia.com/docs/library/html/qt4/qapplication.html
    char zero = 0;
    int d_argc = 1;
    char* d_argv = &zero;
    QWidget* d_parent;
    SpectrumGUIClass d_main_gui;

    void windowreset();
    void buildwindow();
    void fftresize();
    void check_clicked();
    void fft(float* data_out, const float* data_in, int size);

    // Handles message input port for setting new center frequency.
    // The message is a PMT pair (intern('freq'), double(frequency)).
    void handle_set_freq(pmt::pmt_t msg);

public:
    sink_f_impl(int fftsize,
                int wintype,
                double fc,
                double bw,
                const std::string& name,
                bool plotfreq,
                bool plotwaterfall,
                bool plottime,
                bool plotconst,
                QWidget* parent);
    ~sink_f_impl() override;
    // Disallow copy/move because of the pointers.
    sink_f_impl(const sink_f_impl&) = delete;
    sink_f_impl(sink_f_impl&&) = delete;
    sink_f_impl& operator=(const sink_f_impl&) = delete;
    sink_f_impl& operator=(sink_f_impl&&) = delete;

    bool check_topology(int ninputs, int noutputs) override;

    void exec_() override;
    QWidget* qwidget() override;

    void set_fft_size(const int fftsize) override;
    int fft_size() const override;

    void set_frequency_range(const double centerfreq, const double bandwidth) override;
    void set_fft_power_db(double min, double max) override;
    void enable_rf_freq(bool en) override;

    // void set_time_domain_axis(double min, double max);
    // void set_constellation_axis(double xmin, double xmax,
    //                            double ymin, double ymax);
    // void set_constellation_pen_size(int size);

    void set_update_time(double t) override;

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items) override;
};

} /* namespace qtgui */
} /* namespace gr */

#endif /* INCLUDED_QTGUI_SINK_F_IMPL_H */
