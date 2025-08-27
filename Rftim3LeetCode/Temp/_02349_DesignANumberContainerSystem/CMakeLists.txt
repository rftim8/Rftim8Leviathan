cmake_minimum_required(VERSION 3.8.0)
project(_02349_DesignANumberContainerSystem VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_02349_DesignANumberContainerSystem main.cpp)

target_link_libraries(_02349_DesignANumberContainerSystem gtest)

target_compile_features(_02349_DesignANumberContainerSystem PUBLIC cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
