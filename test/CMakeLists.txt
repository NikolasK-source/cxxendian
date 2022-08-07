#
# Copyright (C) 2022 Nikolas Koesling <nikolas@koesling.info>.
# This program is free software. You can redistribute it and/or modify it under the terms of the MIT License.
#

add_executable(test_${Target} endiannes_test.cpp)

target_compile_options(test_${Target} PUBLIC -w)

enable_testing()
add_test(NAME test_${Target}  COMMAND test_${Target})

target_link_libraries(test_${Target} ${Target})

# force C++ Standard and disable/enable compiler specific extensions
set_target_properties(test_${Target} PROPERTIES
        CXX_STANDARD ${STANDARD}
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ${COMPILER_EXTENSIONS}
        )

# options that are valid for gcc and clang
function(commonopts)
    # more debugging information
    if(OPTIMIZE_DEBUG)
        SET(CMAKE_CXX_FLAGS_DEBUG "-g3 -O3")
    else()
        SET(CMAKE_CXX_FLAGS_DEBUG "-g3")
    endif()

    if(MAKE_32_BIT_BINARY)
        message(STATUS "Compiling as 32 bit binary.")
        target_compile_options(test_${Target} PUBLIC -m32)
    endif()

    if(ENABLE_MULTITHREADING AND OPENMP)
        message(STATUS "openmp enabled")
        target_compile_options(test_${Target} PUBLIC -fopenmp)
    endif()

    if(OPTIMIZE_FOR_ARCHITECTURE)
        message(STATUS "using architecture specific code generator: ${ARCHITECTURE}")
        target_compile_options(test_${Target} PUBLIC -march=${ARCHITECTURE})
    endif()
endfunction()

# warnings that are valid for gcc and clang
function(commonwarn)
    target_compile_options(test_${Target} PUBLIC -Wall -Wextra -Werror -pedantic -pedantic-errors)

    # see https://gcc.gnu.org/onlinedocs/gcc-4.3.2/gcc/Warning-Options.html for more details

    target_compile_options(test_${Target} PUBLIC -Wnull-dereference)
    target_compile_options(test_${Target} PUBLIC -Wold-style-cast)
    target_compile_options(test_${Target} PUBLIC -Wdouble-promotion)
    target_compile_options(test_${Target} PUBLIC -Wformat=2)
    target_compile_options(test_${Target} PUBLIC -Winit-self)
    target_compile_options(test_${Target} PUBLIC -Wsequence-point)
    target_compile_options(test_${Target} PUBLIC -Wswitch-default)
    target_compile_options(test_${Target} PUBLIC -Wswitch-enum -Wno-error=switch-enum)
    target_compile_options(test_${Target} PUBLIC -Wconversion)
    target_compile_options(test_${Target} PUBLIC -Wcast-align)
    target_compile_options(test_${Target} PUBLIC -Wfloat-equal)
    target_compile_options(test_${Target} PUBLIC -Wundef)
    target_compile_options(test_${Target} PUBLIC -Wcast-qual)
endfunction()

# gcc specific warnings
function(gccwarn)
    # see https://gcc.gnu.org/onlinedocs/gcc-4.3.2/gcc/Warning-Options.html for more details

    target_compile_options(test_${Target} PUBLIC -Wduplicated-cond)
    target_compile_options(test_${Target} PUBLIC -Wduplicated-branches)
    target_compile_options(test_${Target} PUBLIC -Wlogical-op)
    target_compile_options(test_${Target} PUBLIC -Wrestrict)
    target_compile_options(test_${Target} PUBLIC -Wuseless-cast -Wno-error=useless-cast)
    target_compile_options(test_${Target} PUBLIC -Wshadow=local -Wno-error=shadow)

    target_compile_options(test_${Target} PUBLIC -Wno-error=switch-default)
    target_compile_options(test_${Target} PUBLIC -Wno-error=attributes)
endfunction()

# clang specific warnings
function(clangwarn)
    # enable all
    target_compile_options(test_${Target} PUBLIC -Weverything)

    # and remove "useless" ones
    target_compile_options(test_${Target} PUBLIC -Wno-c++98-compat)
    target_compile_options(test_${Target} PUBLIC -Wno-c++98-c++11-c++14-compat)
    target_compile_options(test_${Target} PUBLIC -Wno-c++98-compat-pedantic)
    target_compile_options(test_${Target} PUBLIC -Wno-error=covered-switch-default)
    target_compile_options(test_${Target} PUBLIC -Wno-shadow-field-in-constructor)
    target_compile_options(test_${Target} PUBLIC -Wno-padded)
    target_compile_options(test_${Target} PUBLIC -Wno-shadow-field)
    target_compile_options(test_${Target} PUBLIC -Wno-weak-vtables)
    target_compile_options(test_${Target} PUBLIC -Wno-exit-time-destructors)
    target_compile_options(test_${Target} PUBLIC -Wno-global-constructors)
    target_compile_options(test_${Target} PUBLIC -Wno-error=unreachable-code-return)
    target_compile_options(test_${Target} PUBLIC -Wno-error=unreachable-code)
    target_compile_options(test_${Target} PUBLIC -Wno-error=documentation)
    target_compile_options(test_${Target} PUBLIC -Wno-error=unused-exception-parameter)
    target_compile_options(test_${Target} PUBLIC -Wno-nested-anon-types)
    target_compile_options(test_${Target} PUBLIC -Wno-gnu-anonymous-struct)

endfunction()

if(COMPILER_WARNINGS)
    message(STATUS "Compiler warnings enabled.")
else()
    message(STATUS "Compiler warnings disabled.")
endif()

# compiler settings
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    # compiler specific defines
    target_compile_definitions(test_${Target} PUBLIC "COMPILER_GNU")
    target_compile_definitions(test_${Target} PUBLIC "COMPILER_GNU_CLANG")

    commonopts()

    # enable warnings
    if(COMPILER_WARNINGS)
        commonwarn()
        gccwarn()
    else()
        target_compile_options(test_${Target} PUBLIC -w)
    endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # compiler specific defines
    target_compile_definitions(test_${Target} PUBLIC "COMPILER_CLANG")
    target_compile_definitions(test_${Target} PUBLIC "COMPILER_GNU_CLANG")

    commonopts()

    # enable warnings (general)
    if(COMPILER_WARNINGS)
        commonwarn()
        clangwarn()
    else()
        target_compile_options(test_${Target} PUBLIC -w)
    endif()

elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # compiler specific defines
    target_compile_definitions(test_${Target} PUBLIC "COMPILER_MSVC")

    # more debugging information
    SET(CMAKE_CXX_FLAGS_DEBUG "/Zi")
    message(AUTHOR_WARNING
            "You are using the MSVC compiler! Only gcc/clang are fully supported by this template.")

    if(COMPILER_WARNINGS)
        target_compile_options(test_${Target} PUBLIC /Wall /WX)
    endif()

    if(ENABLE_MULTITHREADING AND OPENMP)
        target_compile_options(test_${Target} PUBLIC /OpenMP)
    endif()
else()
    message(AUTHOR_WARNING
            "You are using a compiler other than gcc/clang. Only gcc/clang are fully supported by this template.")
endif()

# os dependent defines
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_compile_definitions(test_${Target} PUBLIC "OS_LINUX")
    target_compile_definitions(test_${Target} PUBLIC "OS_POSIX")
elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    target_compile_definitions(test_${Target} PUBLIC "OS_FREEBSD")
    target_compile_definitions(test_${Target} PUBLIC "OS_POSIX")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_compile_definitions(test_${Target} PUBLIC "OS_WINDOWS")
    # TODO check options
    target_compile_options(test_${Target} PUBLIC -D_DLL -D_MT -Xclang --dependent-lib=msvcrtd)
    SET(CMAKE_CXX_FLAGS_DEBUG "-g3 -D_DEBUG")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    target_compile_definitions(test_${Target} PUBLIC "OS_DARWIN")
    target_compile_definitions(test_${Target} PUBLIC "OS_POSIX")
endif()

# architecture defines
target_compile_definitions(test_${Target} PUBLIC CPU_WORD_BYTES=${CMAKE_SIZEOF_VOID_P})