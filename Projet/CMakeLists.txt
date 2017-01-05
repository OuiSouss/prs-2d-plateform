cmake_minimum_required(VERSION 3.6.2)

project(prs-2d-plateform C)
enable_language(C)

add_definitions("-o3 -std=c99 -Wall -Wextra -Wno-unused-function")
include_directories(include)

set(CMAKE_EXE_LINKER_FLAGS "-no-pie ${CMAKE_EXE_LINKER_FLAGS}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/util)

add_executable(maputil src/metadata_io_interface.c util/maputil.c)
