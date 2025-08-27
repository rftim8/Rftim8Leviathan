cmake_minimum_required(VERSION 4.0.1)
project(rftim3_stl_cpp LANGUAGES C CXX)
set(PROJECT_TARGET rftim3_stl_cpp)

add_library(${PROJECT_NAME} INTERFACE)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

