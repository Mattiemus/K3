cmake_minimum_required(VERSION 3.10)

project(openworld_engine_runtime_lua_scripting VERSION 0.1.0)

add_library(${PROJECT_NAME} STATIC 
    "private/api/enums/register_script_language_enum.cpp"
    "private/api/types/register_base_script_usertype.cpp"
    "private/api/types/register_data_model_usertype.cpp"
    "private/api/types/register_folder_usertype.cpp"
    "private/api/types/register_instance_usertype.cpp"
    "private/api/types/register_service_provider_usertype.cpp"
    "private/api/register_api.cpp"
    "private/context/lua_execution_context.cpp")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME} PUBLIC "public/")
target_include_directories(${PROJECT_NAME} PRIVATE "private/")

target_link_libraries(${PROJECT_NAME} PUBLIC openworld_engine_runtime_datamodel sol2 lua_static)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION "public/")