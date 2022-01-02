cmake_minimum_required(VERSION 3.10)

project(openworld_engine_runtime_graphics_gl VERSION 0.1.0)

add_library(${PROJECT_NAME} STATIC
    "private/shader.cpp"
    "private/gl_shader_group.cpp" 
    "private/gl_render_context.cpp"
    "private/gl_render_system.cpp"
    "private/win32/gl_swap_chain.cpp"
    "private/impl/gl_vertex_buffer_impl.cpp"
    "private/impl/gl_index_buffer_impl.cpp" 
    "private/impl/gl_vertex_buffer_impl_factory.cpp"
    "private/impl/gl_index_buffer_impl_factory.cpp")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(${PROJECT_NAME} PUBLIC
    openworld_engine_runtime_core
    openworld_engine_runtime_graphics
    openworld_engine_runtime_math)

target_link_libraries(${PROJECT_NAME} PRIVATE
    libglew_static)

target_include_directories(${PROJECT_NAME} PUBLIC "public/")
target_include_directories(${PROJECT_NAME} PRIVATE "private/")

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION "public/")