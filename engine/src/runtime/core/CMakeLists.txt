cmake_minimum_required(VERSION 3.10)

project(openworld_engine_runtime_core VERSION 0.1.0)

add_library(${PROJECT_NAME} STATIC
    "private/engine/engine.cpp"
    "private/platform/impl/application_host_impl.cpp"
    "private/platform/win32/win32_window.cpp"
    "private/platform/win32/win32_application_host_impl.cpp"
    "private/platform/platform_system.cpp"
    "private/platform/window.cpp")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME} PUBLIC "public/")
target_include_directories(${PROJECT_NAME} PRIVATE "private/")

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION "public/")