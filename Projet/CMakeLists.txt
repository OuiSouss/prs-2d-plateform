cmake_minimum_required(VERSION 3.6.2)

project(prs-2d-plateform C)
enable_language(C)

add_definitions("-o3 -std=c99 -Wall -Wextra -Wno-unused-function -D_REENTRANT -DPADAWAN")
include_directories(include)
include_directories(/usr/include/SDL2)

set(CMAKE_EXE_LINKER_FLAGS "-no-pie ${CMAKE_EXE_LINKER_FLAGS}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin/release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin/debug)

find_package(OpenMP)
if (OPENMP_FOUND)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
endif()

add_executable(game src/mapio.c)
target_link_libraries(game SDL2_image SDL2_mixer SDL2 ${PROJECT_SOURCE_DIR}/lib/libgame.a)
