add_executable(hlbsp)

target_sources(hlbsp
        PRIVATE
        ${COMMON_CPPFILES}
        brink.cpp
        merge.cpp
        outside.cpp
        portals.cpp
        qbsp.cpp
        solidbsp.cpp
        surfaces.cpp
        tjunc.cpp
        writebsp.cpp)

target_include_directories(hlbsp PRIVATE .)

target_compile_definitions(hlbsp PRIVATE HLBSP DOUBLEVEC_T)

target_link_libraries(hlbsp Threads::Threads)

add_custom_command(TARGET hlbsp
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hlbsp> ${CMAKE_SOURCE_DIR}/tools/)