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

#include <gnuradio/qtgui/time_raster_sink_f.h>
// pydoc.h is automatically generated in the build directory
#include <time_raster_sink_f_pydoc.h>

void bind_time_raster_sink_f(py::module& m)
{

    using time_raster_sink_f = ::gr::qtgui::time_raster_sink_f;


    py::class_<time_raster_sink_f,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<time_raster_sink_f>>(
        m, "time_raster_sink_f", D(time_raster_sink_f))

        .def(py::init(&time_raster_sink_f::make),
             py::arg("samp_rate"),
             py::arg("rows"),
             py::arg("cols"),
             py::arg("mult"),
             py::arg("offset"),
             py::arg("name"),
             py::arg("nconnections") = 1,
             py::arg("parent") = nullptr,
             D(time_raster_sink_f, make))


        .def("exec_", &time_raster_sink_f::exec_, D(time_raster_sink_f, exec_))


        .def(
            "qwidget",
            [](time_raster_sink_f& self) {
                return reinterpret_cast<uintptr_t>(self.qwidget());
            },
            D(time_raster_sink_f, qwidget))


        .def("set_x_range",
             &time_raster_sink_f::set_x_range,
             py::arg("min"),
             py::arg("max"),
             D(time_raster_sink_f, set_x_range))


        .def("set_x_label",
             &time_raster_sink_f::set_x_label,
             py::arg("label"),
             D(time_raster_sink_f, set_x_label))


        .def("set_y_range",
             &time_raster_sink_f::set_y_range,
             py::arg("min"),
             py::arg("max"),
             D(time_raster_sink_f, set_y_range))


        .def("set_y_label",
             &time_raster_sink_f::set_y_label,
             py::arg("label"),
             D(time_raster_sink_f, set_y_label))


        .def("set_update_time",
             &time_raster_sink_f::set_update_time,
             py::arg("t"),
             D(time_raster_sink_f, set_update_time))


        .def("set_title",
             &time_raster_sink_f::set_title,
             py::arg("title"),
             D(time_raster_sink_f, set_title))


        .def("set_line_label",
             &time_raster_sink_f::set_line_label,
             py::arg("which"),
             py::arg("label"),
             D(time_raster_sink_f, set_line_label))


        .def("set_line_color",
             &time_raster_sink_f::set_line_color,
             py::arg("which"),
             py::arg("color"),
             D(time_raster_sink_f, set_line_color))


        .def("set_line_width",
             &time_raster_sink_f::set_line_width,
             py::arg("which"),
             py::arg("width"),
             D(time_raster_sink_f, set_line_width))


        .def("set_line_style",
             &time_raster_sink_f::set_line_style,
             py::arg("which"),
             py::arg("style"),
             D(time_raster_sink_f, set_line_style))


        .def("set_line_marker",
             &time_raster_sink_f::set_line_marker,
             py::arg("which"),
             py::arg("marker"),
             D(time_raster_sink_f, set_line_marker))


        .def("set_line_alpha",
             &time_raster_sink_f::set_line_alpha,
             py::arg("which"),
             py::arg("alpha"),
             D(time_raster_sink_f, set_line_alpha))


        .def("set_color_map",
             &time_raster_sink_f::set_color_map,
             py::arg("which"),
             py::arg("color"),
             D(time_raster_sink_f, set_color_map))


        .def("title", &time_raster_sink_f::title, D(time_raster_sink_f, title))


        .def("line_label",
             &time_raster_sink_f::line_label,
             py::arg("which"),
             D(time_raster_sink_f, line_label))


        .def("line_color",
             &time_raster_sink_f::line_color,
             py::arg("which"),
             D(time_raster_sink_f, line_color))


        .def("line_width",
             &time_raster_sink_f::line_width,
             py::arg("which"),
             D(time_raster_sink_f, line_width))


        .def("line_style",
             &time_raster_sink_f::line_style,
             py::arg("which"),
             D(time_raster_sink_f, line_style))


        .def("line_marker",
             &time_raster_sink_f::line_marker,
             py::arg("which"),
             D(time_raster_sink_f, line_marker))


        .def("line_alpha",
             &time_raster_sink_f::line_alpha,
             py::arg("which"),
             D(time_raster_sink_f, line_alpha))


        .def("color_map",
             &time_raster_sink_f::color_map,
             py::arg("which"),
             D(time_raster_sink_f, color_map))


        .def("set_size",
             &time_raster_sink_f::set_size,
             py::arg("width"),
             py::arg("height"),
             D(time_raster_sink_f, set_size))


        .def("set_samp_rate",
             &time_raster_sink_f::set_samp_rate,
             py::arg("samp_rate"),
             D(time_raster_sink_f, set_samp_rate))


        .def("set_num_rows",
             &time_raster_sink_f::set_num_rows,
             py::arg("rows"),
             D(time_raster_sink_f, set_num_rows))


        .def("set_num_cols",
             &time_raster_sink_f::set_num_cols,
             py::arg("cols"),
             D(time_raster_sink_f, set_num_cols))


        .def("num_rows", &time_raster_sink_f::num_rows, D(time_raster_sink_f, num_rows))


        .def("num_cols", &time_raster_sink_f::num_cols, D(time_raster_sink_f, num_cols))


        .def("set_multiplier",
             &time_raster_sink_f::set_multiplier,
             py::arg("mult"),
             D(time_raster_sink_f, set_multiplier))


        .def("set_offset",
             &time_raster_sink_f::set_offset,
             py::arg("offset"),
             D(time_raster_sink_f, set_offset))


        .def("set_intensity_range",
             &time_raster_sink_f::set_intensity_range,
             py::arg("min"),
             py::arg("max"),
             D(time_raster_sink_f, set_intensity_range))


        .def("enable_menu",
             &time_raster_sink_f::enable_menu,
             py::arg("en"),
             D(time_raster_sink_f, enable_menu))


        .def("enable_grid",
             &time_raster_sink_f::enable_grid,
             py::arg("en"),
             D(time_raster_sink_f, enable_grid))


        .def("enable_autoscale",
             &time_raster_sink_f::enable_autoscale,
             py::arg("en"),
             D(time_raster_sink_f, enable_autoscale))


        .def("enable_axis_labels",
             &time_raster_sink_f::enable_axis_labels,
             py::arg("en") = true,
             D(time_raster_sink_f, enable_axis_labels))


        .def("reset", &time_raster_sink_f::reset, D(time_raster_sink_f, reset))

        ;
}
