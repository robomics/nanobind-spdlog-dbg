# Copyright (C) 2024 Roberto Rossini <roberros@uio.no>
#
# SPDX-License-Identifier: MIT

import nanobind_spdlog_dbg


class TestClass:
    def test_logging(self):
        nanobind_spdlog_dbg.do_log(f"version: {nanobind_spdlog_dbg.__version__}")
