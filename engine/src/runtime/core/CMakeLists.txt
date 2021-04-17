cmake_minimum_required(VERSION 3.10)

project(openworld_engine_runtime_core VERSION 0.1.0)

add_library(${PROJECT_NAME} STATIC 
    "private/Todo.cpp" "public/core/math/transform.hpp")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME} PUBLIC "public/")
target_include_directories(${PROJECT_NAME} PRIVATE "private/")

target_link_libraries(${PROJECT_NAME} PUBLIC)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION "public/")