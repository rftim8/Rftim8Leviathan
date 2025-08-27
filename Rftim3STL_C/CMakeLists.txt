cmake_minimum_required(VERSION 3.10.0)
project(rftim3_stl_c LANGUAGES C CXX)
set(PROJECT_TARGET rftim3_stl_c)

add_library(${PROJECT_NAME} INTERFACE)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

