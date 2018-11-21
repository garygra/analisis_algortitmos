cmake_minimum_required (VERSION 2.6)
project (huffman)

add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE Debug)

include_directories(
	include
)

add_library(${PROJECT_NAME}_lib
	src/huffman.cpp
	src/priority_queue.cpp
	src/node.cpp
	)

add_executable(huffman_tests src/tests.cpp)

target_link_libraries(
	huffman_tests
	${PROJECT_NAME}_lib
)
