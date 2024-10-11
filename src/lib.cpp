// Copyright (C) 2024 Roberto Rossini <roberros@uio.no>
//
// SPDX-License-Identifier: MIT

#include <nanobind/nanobind.h>
#include <nanobind/stl/string_view.h>
#include <spdlog/spdlog.h>

static void do_log(std::string_view msg) { spdlog::info(msg); }

namespace nb = nanobind;
NB_MODULE(_nanobind_spdlog_dbg, m) {
  m.doc() = "FOO";

  m.def("do_log", &do_log, nb::arg("message") = "do_log() called");
}
