#include "sorting_algorithms.hpp"

#include <stdlib.h>

sorting_algorithms::~sorting_algorithms()
{
}

void sorting_algorithms::new_fix_array()
{
	int aux_arr[] = {7, 15 ,90 ,68, 75, 60, 20, 25, 70, 86, 34, 40, 50};
	size_arr = 13;
	for (int i = 0; i < size_arr; ++i)
	{
		array[i] = aux_arr[i];
	}
}

void sorting_algorithms::set_array_length(int length_in)
{
	array = new int[length_in];
	size_arr = length_in;
}

void sorting_algorithms::new_random_array()
{
	for (int i = 0; i < size_arr; ++i)
	{
		array[i] = uniform_int_random(MIN_INTEGER, MAX_INTEGER);
	}
}

void sorting_algorithms::print_array()
{
	print_array(array, size_arr);
}

void sorting_algorithms::insertion_sort()
{
	int key, i;
	std::cout << "Starting insertion sort..." << std::endl;
	timer.reset();

	for (int j = 1; j < size_arr; ++j)
	{
		key = array[j];
		i = j - 1;
		while ( i >= 0 && array[i] > key)
		{
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = key;
	}
	double duration = timer.measure();

	std::cout << "Time spent sorting: " << duration << std::endl;
}

void sorting_algorithms::merge_sort()
{	
	int step = 1, n = 1, i_arr = 0, f1_size = 0, f2_size = 0;
	int tot_iters = ceil(log2(size_arr)) ;
	int f1[size_arr], f2[size_arr];
	std::cout << "Starting insertion sort..." << std::endl;
	timer.reset();
	while (n <= tot_iters) {
		bool fill_f1 = true;
		int i_f1 = 0, i_f2 = 0;	
		for (int i = 0; i < size_arr; ++i) {
			if (fill_f1) {
				f1[i_f1] = array[i];
				i_f1++;
			} else {
				f2[i_f2] = array[i];
				i_f2++;
			}
			fill_f1 = (i + 1) % step == 0? !fill_f1 : fill_f1;
		}
		f1_size = i_f1; f2_size = i_f2;
		i_f1 = 0; i_f2 = 0; i_arr = 0;
		int limit_temp = step;
		while (i_f1 < f1_size && i_f2 < f2_size){
			if (limit_temp <= i_f1) {
				while (i_f2 < limit_temp) {
					array[i_arr] = f2[i_f2];
					i_f2++; i_arr++;
				}
				limit_temp += step;
			} else if(limit_temp <= i_f2) {
				while (i_f1 < limit_temp) {
					array[i_arr] = f1[i_f1];
					i_f1++; i_arr++;
				}
				limit_temp += step;
			} else {
				if (f1[i_f1] < f2[i_f2]) {
					array[i_arr] = f1[i_f1];
					i_f1++;
				} else {
					array[i_arr] = f2[i_f2];
					i_f2++;
				}
				i_arr++;
			}
		}
		while (i_f1 < f1_size) {
			array[i_arr] = f1[i_f1];
			i_f1++; i_arr++;
		}
		n++;
		step *= 2;
	}
	double duration = timer.measure();
	std::cout << "Time spent sorting: " << duration << std::endl;
}

void sorting_algorithms::print_array(int arr[], int size)
{
	std::cout << "The array is: " << std::endl << "\t";
	for (int i = 0; i < size - 1; ++i)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[size - 1] << std::endl;
}

double sorting_algorithms::uniform_random()
{
  return rand() / RAND_MAX;
}

int sorting_algorithms::uniform_int_random(int min, int max)
{
  return (rand() % (max + 1 - min)) + min;
}