add_executable(hlvis)

target_sources(hlvis
        PRIVATE
        ${COMMON_CPPFILES}
        flow.cpp
        vis.cpp
        zones.cpp)

target_include_directories(hlvis PRIVATE hlvis)

target_compile_definitions(hlvis PRIVATE HLVIS)

target_link_libraries(hlvis Threads::Threads)

add_custom_command(TARGET hlvis
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hlvis> ${CMAKE_SOURCE_DIR}/tools/)