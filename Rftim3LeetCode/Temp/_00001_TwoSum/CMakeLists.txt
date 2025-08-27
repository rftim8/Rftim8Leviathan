# Project Setup
set(PROJECT_TARGET _00001_TwoSum)

# Add source files
file(
    GLOB all_files
    *.cpp
)

add_executable(${PROJECT_NAME} ${all_files})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Add source directories
target_include_directories(${PROJECT_NAME} PRIVATE 
)

# Link personal libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    gtest
	Rftim3STL
)
