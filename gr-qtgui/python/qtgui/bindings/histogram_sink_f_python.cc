/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/* This file is automatically generated using bindtool */

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/qtgui/utils.h>
#include <qwt_legend.h>
#include <qwt_painter.h>
#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_zoomer.h>
#include <qwt_scale_engine.h>
#include <qwt_scale_widget.h>
#include <qwt_symbol.h>

#include <gnuradio/qtgui/histogram_sink_f.h>
// pydoc.h is automatically generated in the build directory
#include <histogram_sink_f_pydoc.h>

void bind_histogram_sink_f(py::module& m)
{

    using histogram_sink_f = ::gr::qtgui::histogram_sink_f;


    py::class_<histogram_sink_f,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<histogram_sink_f>>(
        m, "histogram_sink_f", D(histogram_sink_f))

        .def(py::init(&histogram_sink_f::make),
             py::arg("size"),
             py::arg("bins"),
             py::arg("xmin"),
             py::arg("xmax"),
             py::arg("name"),
             py::arg("nconnections") = 1,
             py::arg("parent") = nullptr,
             D(histogram_sink_f, make))


        .def("exec_", &histogram_sink_f::exec_, D(histogram_sink_f, exec_))


        .def(
            "qwidget",
            [](histogram_sink_f& self) {
                return reinterpret_cast<uintptr_t>(self.qwidget());
            },
            D(histogram_sink_f, qwidget))


        .def("title", &histogram_sink_f::title, D(histogram_sink_f, title))


        .def("line_label",
             &histogram_sink_f::line_label,
             py::arg("which"),
             D(histogram_sink_f, line_label))


        .def("line_color",
             &histogram_sink_f::line_color,
             py::arg("which"),
             D(histogram_sink_f, line_color))


        .def("line_width",
             &histogram_sink_f::line_width,
             py::arg("which"),
             D(histogram_sink_f, line_width))


        .def("line_style",
             &histogram_sink_f::line_style,
             py::arg("which"),
             D(histogram_sink_f, line_style))


        .def("line_marker",
             &histogram_sink_f::line_marker,
             py::arg("which"),
             D(histogram_sink_f, line_marker))


        .def("line_alpha",
             &histogram_sink_f::line_alpha,
             py::arg("which"),
             D(histogram_sink_f, line_alpha))


        .def("set_size",
             &histogram_sink_f::set_size,
             py::arg("width"),
             py::arg("height"),
             D(histogram_sink_f, set_size))


        .def("enable_menu",
             &histogram_sink_f::enable_menu,
             py::arg("en") = true,
             D(histogram_sink_f, enable_menu))


        .def("enable_grid",
             &histogram_sink_f::enable_grid,
             py::arg("en") = true,
             D(histogram_sink_f, enable_grid))


        .def("enable_autoscale",
             &histogram_sink_f::enable_autoscale,
             py::arg("en") = true,
             D(histogram_sink_f, enable_autoscale))


        .def("enable_semilogx",
             &histogram_sink_f::enable_semilogx,
             py::arg("en") = true,
             D(histogram_sink_f, enable_semilogx))


        .def("enable_semilogy",
             &histogram_sink_f::enable_semilogy,
             py::arg("en") = true,
             D(histogram_sink_f, enable_semilogy))


        .def("enable_accumulate",
             &histogram_sink_f::enable_accumulate,
             py::arg("en") = true,
             D(histogram_sink_f, enable_accumulate))


        .def("enable_axis_labels",
             &histogram_sink_f::enable_axis_labels,
             py::arg("en") = true,
             D(histogram_sink_f, enable_axis_labels))


        .def("autoscalex", &histogram_sink_f::autoscalex, D(histogram_sink_f, autoscalex))


        .def("nsamps", &histogram_sink_f::nsamps, D(histogram_sink_f, nsamps))


        .def("bins", &histogram_sink_f::bins, D(histogram_sink_f, bins))


        .def("reset", &histogram_sink_f::reset, D(histogram_sink_f, reset))


        .def("set_y_axis",
             &histogram_sink_f::set_y_axis,
             py::arg("min"),
             py::arg("max"),
             D(histogram_sink_f, set_y_axis))


        .def("set_x_axis",
             &histogram_sink_f::set_x_axis,
             py::arg("min"),
             py::arg("max"),
             D(histogram_sink_f, set_x_axis))


        .def("set_update_time",
             &histogram_sink_f::set_update_time,
             py::arg("t"),
             D(histogram_sink_f, set_update_time))


        .def("set_title",
             &histogram_sink_f::set_title,
             py::arg("title"),
             D(histogram_sink_f, set_title))


        .def("set_line_label",
             &histogram_sink_f::set_line_label,
             py::arg("which"),
             py::arg("line"),
             D(histogram_sink_f, set_line_label))


        .def("set_line_color",
             &histogram_sink_f::set_line_color,
             py::arg("which"),
             py::arg("color"),
             D(histogram_sink_f, set_line_color))


        .def("set_line_width",
             &histogram_sink_f::set_line_width,
             py::arg("which"),
             py::arg("width"),
             D(histogram_sink_f, set_line_width))


        .def("set_line_style",
             &histogram_sink_f::set_line_style,
             py::arg("which"),
             py::arg("style"),
             D(histogram_sink_f, set_line_style))


        .def("set_line_marker",
             &histogram_sink_f::set_line_marker,
             py::arg("which"),
             py::arg("marker"),
             D(histogram_sink_f, set_line_marker))


        .def("set_line_alpha",
             &histogram_sink_f::set_line_alpha,
             py::arg("which"),
             py::arg("alpha"),
             D(histogram_sink_f, set_line_alpha))


        .def("set_nsamps",
             &histogram_sink_f::set_nsamps,
             py::arg("newsize"),
             D(histogram_sink_f, set_nsamps))


        .def("set_bins",
             &histogram_sink_f::set_bins,
             py::arg("bins"),
             D(histogram_sink_f, set_bins))


        .def("disable_legend",
             &histogram_sink_f::disable_legend,
             D(histogram_sink_f, disable_legend))

        ;
}
