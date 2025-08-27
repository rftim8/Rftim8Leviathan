cmake_minimum_required(VERSION 3.5.0)
project(_03221_MaximumArrayHoppingScoreII VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_03221_MaximumArrayHoppingScoreII main.cpp)

target_link_libraries(_03221_MaximumArrayHoppingScoreII gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
