cmake_minimum_required(VERSION 3.8)

project(K3)

add_subdirectory(third_party/lua)
add_subdirectory(third_party/sol2)
add_subdirectory(third_party/glew)

add_subdirectory(engine)
add_subdirectory(game)
