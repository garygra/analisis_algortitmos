cmake_minimum_required (VERSION 2.6)
project (karatsuba)

add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE Debug)

include_directories(
	include
)

add_executable(karatsuba src/karatsuba.cpp)

target_link_libraries(
	karatsuba
)