# Copyright (C) 2024 Roberto Rossini <roberros@uio.no>
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.25)
cmake_policy(VERSION 3.25...3.30)
set(CMAKE_POLICY_DEFAULT_CMP0069 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

project(nanobind-spdlog-dbg LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  spdlog
  URL
    "${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog-v1.14.1.tar.xz"
  URL_HASH "SHA256=0f6bcb66cf830b0651bedfd71733588e35ed4fb3ad9f7e1cb3ea2a98259d3cf4"
  EXCLUDE_FROM_ALL
  SYSTEM
)

FetchContent_Declare(
  nanobind
  URL
    "${CMAKE_CURRENT_SOURCE_DIR}/external/nanobind-v2.2.0.tar.xz"
  URL_HASH "SHA256=6f0064c5e94b0bc34637644ddf035cdc7831135949b843adf52bc4bdbe2c6b5d"
  EXCLUDE_FROM_ALL
  SYSTEM
)

FetchContent_MakeAvailable(
  spdlog
  nanobind
)

find_package(
  Python
  3.9
  COMPONENTS
    Interpreter
    Development.Module
  REQUIRED
)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE "cxx_std_${CMAKE_CXX_STANDARD}")

if(WIN32)
  target_compile_definitions(
    project_options
    INTERFACE
      NOMINMAX
      _CRT_SECURE_NO_WARNINGS
  )
endif()

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif()

add_subdirectory(src)
