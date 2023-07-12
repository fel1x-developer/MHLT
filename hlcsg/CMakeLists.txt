add_executable(hlcsg)

target_sources(hlcsg
        PRIVATE
        ${COMMON_CPPFILES}
        ansitoutf8.cpp
        autowad.cpp
        brush.cpp
        brushunion.cpp
        hullfile.cpp
        map.cpp
        properties.cpp
        qcsg.cpp
        textures.cpp
        wadcfg.cpp
        wadinclude.cpp
        wadpath.cpp)

target_include_directories(hlcsg PRIVATE hlcsg)

target_compile_definitions(hlcsg PRIVATE HLCSG DOUBLEVEC_T)

target_link_libraries(hlcsg Threads::Threads)

add_custom_command(TARGET hlcsg
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hlcsg> ${CMAKE_SOURCE_DIR}/tools/)