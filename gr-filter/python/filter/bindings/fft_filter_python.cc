/*
 * Copyright 2020 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(fft_filter.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(dad8d136a3842f0e989324232efb2949)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/filter/fft_filter.h>
// pydoc.h is automatically generated in the build directory
#include <fft_filter_pydoc.h>

void bind_fft_filter(py::module& m)
{
    py::module m_kernel = m.def_submodule("kernel");

    using fft_filter_fff = gr::filter::kernel::fft_filter_fff;
    using fft_filter_ccc = gr::filter::kernel::fft_filter_ccc;
    using fft_filter_ccf = gr::filter::kernel::fft_filter_ccf;


    py::class_<fft_filter_fff, std::shared_ptr<fft_filter_fff>>(
        m_kernel, "fft_filter_fff", D(kernel, fft_filter_fff))

        .def(py::init<int, std::vector<float, std::allocator<float>> const&, int>(),
             py::arg("decimation"),
             py::arg("taps"),
             py::arg("nthreads") = 1)

        .def("set_taps",
             &fft_filter_fff::set_taps,
             py::arg("taps"),
             D(kernel, fft_filter_fff, set_taps))
        .def("set_nthreads",
             &fft_filter_fff::set_nthreads,
             py::arg("n"),
             D(kernel, fft_filter_fff, set_nthreads))


        .def("taps", &fft_filter_fff::taps, D(kernel, fft_filter_fff, taps))


        .def("ntaps", &fft_filter_fff::ntaps, D(kernel, fft_filter_fff, ntaps))


        .def("nthreads", &fft_filter_fff::nthreads, D(kernel, fft_filter_fff, nthreads))


        .def("filter",
             &fft_filter_fff::filter,
             py::arg("nitems"),
             py::arg("input"),
             py::arg("output"),
             D(kernel, fft_filter_fff, filter));


    py::class_<fft_filter_ccc, std::shared_ptr<fft_filter_ccc>>(
        m_kernel, "fft_filter_ccc", D(kernel, fft_filter_ccc))

        .def(py::init<int,
                      std::vector<std::complex<float>,
                                  std::allocator<std::complex<float>>> const&,
                      int>(),
             py::arg("decimation"),
             py::arg("taps"),
             py::arg("nthreads") = 1,
             D(kernel, fft_filter_ccc, fft_filter_ccc))

        .def("set_taps",
             &fft_filter_ccc::set_taps,
             py::arg("taps"),
             D(kernel, fft_filter_ccc, set_taps))
        .def("set_nthreads",
             &fft_filter_ccc::set_nthreads,
             py::arg("n"),
             D(kernel, fft_filter_ccc, set_nthreads))


        .def("taps", &fft_filter_ccc::taps, D(kernel, fft_filter_ccc, taps))


        .def("ntaps", &fft_filter_ccc::ntaps, D(kernel, fft_filter_ccc, ntaps))


        .def("nthreads", &fft_filter_ccc::nthreads, D(kernel, fft_filter_ccc, nthreads))


        .def("filter",
             &fft_filter_ccc::filter,
             py::arg("nitems"),
             py::arg("input"),
             py::arg("output"),
             D(kernel, fft_filter_ccc, filter));


    py::class_<fft_filter_ccf, std::shared_ptr<fft_filter_ccf>>(
        m_kernel, "fft_filter_ccf", D(kernel, fft_filter_ccf))

        .def(py::init<int, std::vector<float, std::allocator<float>> const&, int>(),
             py::arg("decimation"),
             py::arg("taps"),
             py::arg("nthreads") = 1,
             D(kernel, fft_filter_ccf, fft_filter_ccf))

        .def("set_taps",
             &fft_filter_ccf::set_taps,
             py::arg("taps"),
             D(kernel, fft_filter_ccf, set_taps))
        .def("set_nthreads",
             &fft_filter_ccf::set_nthreads,
             py::arg("n"),
             D(kernel, fft_filter_ccf, set_nthreads))


        .def("taps", &fft_filter_ccf::taps, D(kernel, fft_filter_ccf, taps))


        .def("ntaps", &fft_filter_ccf::ntaps, D(kernel, fft_filter_ccf, ntaps))


        .def("filtersize",
             &fft_filter_ccf::filtersize,
             D(kernel, fft_filter_ccf, filtersize))


        .def("nthreads", &fft_filter_ccf::nthreads, D(kernel, fft_filter_ccf, nthreads))


        .def("filter",
             &fft_filter_ccf::filter,
             py::arg("nitems"),
             py::arg("input"),
             py::arg("output"),
             D(kernel, fft_filter_ccf, filter));
}
