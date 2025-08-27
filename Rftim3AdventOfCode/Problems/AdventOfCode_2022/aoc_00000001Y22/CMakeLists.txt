set(PROJECT_TARGET aoc_00000001Y22)

file(
    GLOB all_files
    *.cc
)

if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()

find_package(PostgreSQL REQUIRED)
find_package(libpqxx CONFIG REQUIRED)

add_executable(${PROJECT_NAME} ${all_files})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} PRIVATE 
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    PostgreSQL::PostgreSQL
    libpqxx::pqxx
	rftim3_stl_cpp
)
