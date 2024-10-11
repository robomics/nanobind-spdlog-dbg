# Copyright (C) 2024 Roberto Rossini <roberros@uio.no>
#
# SPDX-License-Identifier: MIT

nanobind_add_module(
        _nanobind_spdlog_dbg
        NB_STATIC
        LTO
        MODULE
        lib.cpp
)

target_link_libraries(
  _nanobind_spdlog_dbg
  PRIVATE
    project_options
    spdlog::spdlog_header_only
)

install(TARGETS _nanobind_spdlog_dbg LIBRARY DESTINATION nanobind_spdlog_dbg)
