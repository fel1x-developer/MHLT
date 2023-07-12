add_executable(hlrad)

target_sources(hlrad
        PRIVATE
        ${COMMON_CPPFILES}
        compress.cpp
        lerp.cpp
        lightmap.cpp
        loadtextures.cpp
        mathutil.cpp
        nomatrix.cpp
        qrad.cpp
        qradutil.cpp
        sparse.cpp
        trace.cpp
        transfers.cpp
        transparency.cpp
        vismatrix.cpp
        vismatrixutil.cpp)

target_include_directories(hlrad PRIVATE hlrad)

target_compile_definitions(hlrad PRIVATE HLRAD)

target_link_libraries(hlrad Threads::Threads)

add_custom_command(TARGET hlrad
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hlrad> ${CMAKE_SOURCE_DIR}/tools/)