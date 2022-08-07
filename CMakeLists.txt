#
# Copyright (C) 2022 Nikolas Koesling <nikolas@koesling.info>.
# This program is free software. You can redistribute it and/or modify it under the terms of the MIT License.
#

cmake_minimum_required(VERSION 3.13.4 FATAL_ERROR)

# ----------------------------------------------- User settings --------------------------------------------------------
# ======================================================================================================================

# project
project(CXXEndian LANGUAGES CXX VERSION 0.0.1)

set(Target "cxxendian")        # library name
set(STANDARD 17)                  # C++ Standard
set(ARCHITECTURE "native")        # CPU architecture to optimize for (only relevant if OPTIMIZE_FOR_ARCHITECTURE is ON)

option(BUILD_DOC "Build documentation" ON)
option(COMPILER_WARNINGS "Enable compiler warnings" ON)
option(OPTIMIZE_DEBUG "apply optimizations also in debug mode" ON)
option(CLANG_FORMAT "use clang-format" ON)
option(OPTIMIZE_FOR_ARCHITECTURE "enable optimizations for specified architecture" OFF)
option(COMPILER_EXTENSIONS "enable compiler specific C++ extensions" OFF)
option(BUILD_TESTS "build test executables" ON)

# ======================================================================================================================
# ======================================================================================================================


# ----------------------------------------------- Do not change --------------------------------------------------------
# ======================================================================================================================

include(CTest)
include(ClangFormat.cmake)

add_library(${Target} INTERFACE)

# set source and include directory
target_include_directories(${Target} INTERFACE include)

# Determine whether this is a standalone project or included by other projects
set(STANDALONE_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(STANDALONE_PROJECT ON)
endif()

if(BUILD_TESTS AND STANDALONE_PROJECT)
    add_subdirectory(test)
endif()

if (NOT STANDALONE_PROJECT)
    unset(COMPILER_WARNINGS)
endif()

if(BUILD_DOC)
    # doxygen documentation (https://vicrucann.github.io/tutorials/quick-cmake-doxygen/)
    # check if Doxygen is installed
    find_package(Doxygen)
    if (DOXYGEN_FOUND)
        # set input and output files
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

        if(EXISTS ${DOXYGEN_IN})
            # request to configure the file
            configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
            message(STATUS "Doxygen configured")

            # note the option ALL which allows to build the docs together with the application
            add_custom_target( doc_doxygen ALL
                    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    COMMENT "Generating API documentation with Doxygen"
                    VERBATIM )
            message(STATUS "Added target doc_doxygen")
        else()
            message(WARNING "doxygen documentation requested, but file ${DOXYGEN_IN} does not exist.")
        endif()
    else (DOXYGEN_FOUND)
        message(WARNING "Doxygen need to be installed and accessible to generate the doxygen documentation.")
    endif (DOXYGEN_FOUND)
endif()

# add clang format target
if(CLANG_FORMAT)
    add_executable(cf_dummy)
    add_subdirectory(include)
    add_subdirectory(src)
    set(CLANG_FORMAT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/.clang-format)
    if(EXISTS ${CLANG_FORMAT_FILE})
        include(ClangFormat.cmake)
        target_clangformat_setup(cf_dummy)
        message(STATUS "Added clang format target(s)")
    else()
        message(WARNING "Clang format enabled, but file ${CLANG_FORMAT_FILE}  does not exist")
    endif()
endif()
