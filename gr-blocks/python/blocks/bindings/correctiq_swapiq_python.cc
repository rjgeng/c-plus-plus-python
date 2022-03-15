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
/* BINDTOOL_HEADER_FILE(correctiq_swapiq.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(fe94f1e37a636f114ac56074111b937a)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/blocks/correctiq_swapiq.h>
// pydoc.h is automatically generated in the build directory
#include <correctiq_swapiq_pydoc.h>

void bind_correctiq_swapiq(py::module& m)
{

    using swap_iq = ::gr::blocks::swap_iq;


    py::class_<swap_iq,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<swap_iq>>(m, "swap_iq", D(swap_iq))

        .def(py::init(&swap_iq::make),
             py::arg("datatype"),
             py::arg("datasize"),
             D(swap_iq, make))


        ;
}
