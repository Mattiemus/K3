cmake_minimum_required(VERSION 3.8)

add_executable(K3 "K3.cpp")

find_package(OpenGL)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(${PROJECT_NAME} PRIVATE
	libglew_static
    ${OPENGL_gl_LIBRARY}
	openworld_engine_runtime_core
    openworld_engine_runtime_math
	openworld_engine_runtime_ecs
	openworld_engine_runtime_graphics
	openworld_engine_runtime_graphics_gl)
