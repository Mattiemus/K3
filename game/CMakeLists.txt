cmake_minimum_required(VERSION 3.8)

add_executable(K3 "K3.cpp")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(${PROJECT_NAME} PRIVATE openworld_engine_runtime_core openworld_engine_runtime_data_model)
