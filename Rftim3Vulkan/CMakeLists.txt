# Project Setup
set(PROJECT_TARGET rft_vulkan)

# Add source files
file(
    GLOB all_files
    *.cc
)

add_executable(${PROJECT_NAME} ${all_files})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Add source directories
target_include_directories(${PROJECT_NAME} PRIVATE 
)

# Link personal libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
  rftim3_stl_cpp
  Rftim3VKEngine
)

if(WIN32)
  add_custom_command(TARGET Rftim3Vulkan POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      $<TARGET_FILE:Rftim3VKEngine>
      $<TARGET_FILE_DIR:Rftim3Vulkan>
  )
endif()
