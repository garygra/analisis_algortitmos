cmake_minimum_required (VERSION 2.6)
project (shortest-path)

add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE Debug)

include_directories(
	include
)

add_library(${PROJECT_NAME}_lib
	src/dijkstra.cpp
	)

add_executable(shortest-path src/shortest-path.cpp)
# add_executable(normal_mul src/normal_mul.cpp)

target_link_libraries(
	shortest-path
	${PROJECT_NAME}_lib
)

# target_link_libraries(
# 	normal_mul
# 	${PROJECT_NAME}_lib
# )