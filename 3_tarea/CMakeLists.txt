cmake_minimum_required (VERSION 2.6)
project (3_tarea)

add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE Debug)

# include_directories(
# 	include
# )

# add_library(${PROJECT_NAME}_lib
# 	src/timer.cpp
# 	src/sorting_algorithms.cpp
# 	)


add_executable(calcs src/calcs.cpp)

target_link_libraries(
	calcs 
	# ${PROJECT_NAME}_lib
)