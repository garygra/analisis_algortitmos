cmake_minimum_required (VERSION 2.6)
project (mochila)

add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE Debug)


find_package (Eigen3 REQUIRED NO_MODULE)


# add_library(${PROJECT_NAME}_lib
# 	src/timer.cpp
# 	src/sorting_algorithms.cpp
# 	)


include_directories(
	# include
	EIGEN3_INCLUDE_DIR
	)

# add_executable(matrices src/example.cpp)
add_executable(mochila src/mochila.cpp)

# target_link_libraries(
# 	matrices 
# 	# ${PROJECT_NAME}_lib
# 	Eigen3::Eigen
# )