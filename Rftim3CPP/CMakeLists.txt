# Project Setup
set(PROJECT_TARGET rftim3_cpp)

# Add source files
file(
    GLOB all_files
    *.cc
    syntax/*.cc
)

add_executable(${PROJECT_NAME} ${all_files})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Add source directories
target_include_directories(${PROJECT_NAME} PRIVATE 
    syntax
)

# Link personal libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
	rftim3_stl_cpp
)

