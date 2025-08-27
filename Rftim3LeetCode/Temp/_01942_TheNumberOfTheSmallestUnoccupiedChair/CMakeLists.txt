cmake_minimum_required(VERSION 3.5.0)
project(_01942_TheNumberOfTheSmallestUnoccupiedChair VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_01942_TheNumberOfTheSmallestUnoccupiedChair main.cpp)

target_link_libraries(_01942_TheNumberOfTheSmallestUnoccupiedChair gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
