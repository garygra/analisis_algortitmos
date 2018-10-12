cmake_minimum_required (VERSION 2.6)
project (karatsuba)

add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE Debug)

include_directories(
	include
)

add_library(${PROJECT_NAME}_lib
	src/timer.cpp
	)

add_executable(karatsuba src/karatsuba.cpp)
add_executable(normal_mul src/normal_mul.cpp)

target_link_libraries(
	karatsuba
	${PROJECT_NAME}_lib
)

target_link_libraries(
	normal_mul
	${PROJECT_NAME}_lib
)