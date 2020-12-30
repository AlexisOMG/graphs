cmake_minimum_required(VERSION 3.16)
project(graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)
include_directories(include src)
target_include_directories(${PROJECT_NAME} PUBLIC include src)
file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(graph_lib STATIC ${sources})
target_link_libraries(${PROJECT_NAME} PRIVATE graph_lib)

