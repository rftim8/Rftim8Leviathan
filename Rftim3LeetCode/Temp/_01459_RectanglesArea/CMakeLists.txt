cmake_minimum_required(VERSION 3.5.0)
project(_01459_RectanglesArea VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_01459_RectanglesArea main.cpp)

target_link_libraries(_01459_RectanglesArea gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
