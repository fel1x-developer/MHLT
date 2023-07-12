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
        common/blockmem.cpp
        common/bspfile.cpp
        common/cmdlib.cpp
        common/cmdlinecfg.cpp
        common/filelib.cpp
        common/log.cpp
        common/mathlib.cpp
        common/messages.cpp
        common/scriplib.cpp
        common/threads.cpp
        common/winding.cpp)

set(COMMON_INCLUDEFILES
        common/blockmem.h
        common/boundingbox.h
        common/bspfile.h
        common/cmdlib.h
        common/cmdlinecfg.h
        common/filelib.h
        common/hlassert.h
        common/log.h
        common/mathlib.h
        common/mathtypes.h
        common/messages.h
        common/scriplib.h
        common/threads.h
        common/win32fix.h
        common/winding.h)

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

#
# Specific .cpp and .h files for hlcsg, hlbsp, hlvis, hlrad and ripent
#

#
# hlbsp
#

add_executable(hlbsp)

target_sources(hlbsp
        PRIVATE
        ${COMMON_CPPFILES}
        hlbsp/brink.cpp
        hlbsp/merge.cpp
        hlbsp/outside.cpp
        hlbsp/portals.cpp
        hlbsp/qbsp.cpp
        hlbsp/solidbsp.cpp
        hlbsp/surfaces.cpp
        hlbsp/tjunc.cpp
        hlbsp/writebsp.cpp)

target_include_directories(hlbsp PRIVATE hlbsp)

target_compile_definitions(hlbsp PRIVATE HLBSP DOUBLEVEC_T)

target_link_libraries(hlbsp Threads::Threads)

add_custom_command(TARGET hlbsp
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hlbsp> ${CMAKE_SOURCE_DIR}/tools/)

#
# hlcsg
#

add_executable(hlcsg)

target_sources(hlcsg
        PRIVATE
        ${COMMON_CPPFILES}
        hlcsg/ansitoutf8.cpp
        hlcsg/autowad.cpp
        hlcsg/brush.cpp
        hlcsg/brushunion.cpp
        hlcsg/hullfile.cpp
        hlcsg/map.cpp
        hlcsg/properties.cpp
        hlcsg/qcsg.cpp
        hlcsg/textures.cpp
        hlcsg/wadcfg.cpp
        hlcsg/wadinclude.cpp
        hlcsg/wadpath.cpp)

target_include_directories(hlcsg PRIVATE hlcsg)

target_compile_definitions(hlcsg PRIVATE HLCSG DOUBLEVEC_T)

target_link_libraries(hlcsg Threads::Threads)

add_custom_command(TARGET hlcsg
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hlcsg> ${CMAKE_SOURCE_DIR}/tools/)

#
# hlrad
#

add_executable(hlrad)

target_sources(hlrad
        PRIVATE
        ${COMMON_CPPFILES}
        hlrad/compress.cpp
        hlrad/lerp.cpp
        hlrad/lightmap.cpp
        hlrad/loadtextures.cpp
        hlrad/mathutil.cpp
        hlrad/nomatrix.cpp
        hlrad/qrad.cpp
        hlrad/qradutil.cpp
        hlrad/sparse.cpp
        hlrad/trace.cpp
        hlrad/transfers.cpp
        hlrad/transparency.cpp
        hlrad/vismatrix.cpp
        hlrad/vismatrixutil.cpp)

target_include_directories(hlrad PRIVATE hlrad)

target_compile_definitions(hlrad PRIVATE HLRAD)

target_link_libraries(hlrad Threads::Threads)

add_custom_command(TARGET hlrad
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hlrad> ${CMAKE_SOURCE_DIR}/tools/)

#
# hlvis
#

add_executable(hlvis)

target_sources(hlvis
        PRIVATE
        ${COMMON_CPPFILES}
        hlvis/flow.cpp
        hlvis/vis.cpp
        hlvis/zones.cpp)

target_include_directories(hlvis PRIVATE hlvis)

target_compile_definitions(hlvis PRIVATE HLVIS)

target_link_libraries(hlvis Threads::Threads)

add_custom_command(TARGET hlvis
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hlvis> ${CMAKE_SOURCE_DIR}/tools/)

#
# ripent
#

add_executable(ripent)

target_sources(ripent
        PRIVATE
        ${COMMON_CPPFILES}
        ripent/ripent.cpp)

target_include_directories(ripent PRIVATE ripent)

target_compile_definitions(ripent PRIVATE RIPENT)

target_link_libraries(ripent Threads::Threads)

add_custom_command(TARGET ripent
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ripent> ${CMAKE_SOURCE_DIR}/tools/)