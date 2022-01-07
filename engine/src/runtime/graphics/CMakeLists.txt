cmake_minimum_required(VERSION 3.10)

project(openworld_engine_runtime_graphics VERSION 0.1.0)

add_library(${PROJECT_NAME} STATIC
    "private/vertex_layout.cpp"
    "private/vertex_structures.cpp"
    "private/vertex_buffer.cpp"    
    "private/index_buffer.cpp"
    "private/occlusion_query.cpp"
    "private/blend_state.cpp"
    "private/msaa_description.cpp"
    "private/depth_stencil_state.cpp"
    "private/sampler_state.cpp"
    "private/rasterizer_state.cpp"
    "private/impl/index_buffer_impl.cpp"
    "private/impl/vertex_buffer_impl.cpp"
    "private/impl/texture_1d_impl.cpp"
    "private/texture_1d.cpp" "private/texture_1d_array.cpp")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(${PROJECT_NAME} PUBLIC
    openworld_engine_runtime_core
    openworld_engine_runtime_math)

target_include_directories(${PROJECT_NAME} PUBLIC "public/")
target_include_directories(${PROJECT_NAME} PRIVATE "private/")

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION "public/")