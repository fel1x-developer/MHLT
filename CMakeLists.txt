# Usage:
#   make            - Build all tools. They will be copied into 'bin' directory.
#   make clean      - Clean.
#   make hlcsg      - Build hlcsg.
#   make hlbsp      - Build hlbsp.
#   make hlvis      - Build hlvis.
#   make hlrad      - Build hlrad.
#   make ripent     - Build ripent.
#
# Before running the tools, please make sure the default maximum stack size on your computer
#   is more than 4MB.
#
# When compiling with g++:
#   Flag '-fno-strict-aliasing' is a must.
#   All macro definitions should not be changed, because all code were written and checked under this assumption.
#   The following warnings should be ignored:
#     warning: no newline at end of file
#     warning: '???' may be used uninitialized in this function
#     warning: suggest parentheses around assignment used as truth value
#     warning: passing ‘float’ for argument 1 to ‘void seconds_to_hhmm(unsigned int, unsigned int&, unsigned int&, unsigned int&, unsigned int&)’
#     warning: ignoring #pragma warning
#     warning: comparison between signed and unsigned integer expressions
#     warning: enumeration value ‘???’ not handled in switch
#     warning: unused variable ‘???’
#     warning: converting to ‘int’ from ‘vec_t’
#

cmake_minimum_required(VERSION 3.23)

project(ModernHalfLifeTools
        VERSION 1.0.0
        DESCRIPTION "Modern Half Life Tools"
        LANGUAGES CXX)

if (UNIX)
    set(CMAKE_C_COMPILER cc)
    set(CMAKE_CPP_COMPILER c++)
endif (UNIX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find dependencies
find_package(Threads REQUIRED)

#
# Common .cpp and .h files for all projects
#

include_directories(template common)

set(COMMON_CPPFILES
        ../common/blockmem.cpp
        ../common/bspfile.cpp
        ../common/cmdlib.cpp
        ../common/cmdlinecfg.cpp
        ../common/filelib.cpp
        ../common/log.cpp
        ../common/mathlib.cpp
        ../common/messages.cpp
        ../common/scriplib.cpp
        ../common/threads.cpp
        ../common/winding.cpp)

if (UNIX)
    add_compile_definitions(
            VERSION_POSIX
            SYSTEM_POSIX
            NDEBUG
            STDC_HEADERS
            HAVE_FCNTL_H
            HAVE_PTHREAD_H
            HAVE_SYS_RESOURCE_H
            HAVE_SYS_STAT_H
            HAVE_SYS_TIME_H
            HAVE_UNISTD_H)
endif (UNIX)

if (MSVC)
    add_compile_definitions(
            VERSION_WINDOWS
            NDEBUG
            WIN32
            _CONSOLE
            SYSTEM_WIN32
            STDC_HEADERS)
endif (MSVC)

if (UNIX)
    set(CMAKE_CXX_FLAGS "-Wall -O2 -fno-strict-aliasing -pipe")
endif (UNIX)

if (MSVC)
    set(CMAKE_CXX_FLAGS "/GS /GL /W3 /Gy /Zc:wchar_t /Zi /Gm- /O2 /Zc:inline /fp:precise /GF /WX- /Zc:forScope /Gd /Oi /MT /FC /EHsc /nologo")
    add_link_options("-LTCG -SUBSYSTEM:CONSOLE -NOLOGO")
endif (MSVC)

add_subdirectory(hlbsp)
add_subdirectory(hlcsg)
add_subdirectory(hlrad)
add_subdirectory(hlvis)
add_subdirectory(ripent)