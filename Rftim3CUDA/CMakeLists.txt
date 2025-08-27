# Project Setup
set(PROJECT_TARGET rft_cuda)
set(CMAKE_CUDA_ARCHITECTURES 60 61 70 75 80 86)

# Add source files
file(
	GLOB all_files
	*.cu
	*.cc
)

add_executable(${PROJECT_NAME} ${all_files})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Add source directories
target_include_directories(${PROJECT_NAME} PRIVATE 
)

# Link CUDA libraries
if(CMAKE_CUDA_COMPILER)
target_link_libraries(${PROJECT_NAME} PRIVATE
	CUDA::cudart
	CUDA::cuda_driver
)
else()
message(STATUS "No CUDA compiler found")
endif()

# Link personal libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
	rftim3_stl_cpp
)
