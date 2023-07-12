add_executable(ripent)

target_sources(ripent
        PRIVATE
        ${COMMON_CPPFILES}
        ripent.cpp)

target_include_directories(ripent PRIVATE ripent)

target_compile_definitions(ripent PRIVATE RIPENT)

target_link_libraries(ripent Threads::Threads)

add_custom_command(TARGET ripent
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ripent> ${CMAKE_SOURCE_DIR}/tools/)