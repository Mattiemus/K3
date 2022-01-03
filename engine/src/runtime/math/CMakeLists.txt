cmake_minimum_required(VERSION 3.10)

project(openworld_engine_runtime_math VERSION 0.1.0)

add_library(${PROJECT_NAME} STATIC
    "private/float4x4.cpp"
    "private/color.cpp")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(${PROJECT_NAME} PUBLIC
    openworld_engine_runtime_core)

target_include_directories(${PROJECT_NAME} PUBLIC "public/")
target_include_directories(${PROJECT_NAME} PRIVATE "private/")

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION "public/")