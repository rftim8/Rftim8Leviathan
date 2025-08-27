# 1. Create a shared library target
cmake_minimum_required(VERSION 4.0.1)
project(Rftim3VKEngine LANGUAGES C CXX)
set(PROJECT_TARGET Rftim3VKEngine)

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Vulkan REQUIRED)

# Add source files
file(
    GLOB all_files
    src/core/*.cc
    src/platform/*.cc
)

add_library(${PROJECT_NAME} SHARED
  ${all_files}
)

# 2. How users see our headers
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/core>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/platform>
  $<INSTALL_INTERFACE:include>
  $<INSTALL_INTERFACE:include/core>
  $<INSTALL_INTERFACE:include/platform>
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
  glfw
  glm::glm
  Vulkan::Vulkan
)

# 3. Symbol-export macro for Windows + visibility on Unix
#    BUILDING_VKEngine is only set when building the library itself
target_compile_definitions(${PROJECT_NAME} PRIVATE 
  BUILDING_Rftim3VKEngine
)

# 4. (Optional) auto-export all symbols on MSVC, avoids __declspec on every function
if(MSVC)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()
