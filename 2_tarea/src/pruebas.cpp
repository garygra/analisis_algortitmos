#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "sorting_algorithms.hpp"


int main (int argc, char *argv[])
{
	if (argc < 3)
	{
		printf("Usage: %s array_size sorting_alg\n",argv[0]);
		printf("Sorting Algorithms:\n");
		printf("\t0 - insertion\n\t1 - merge\n");
		return 1;
	}
	else
	{
		printf("Using array of length: %s\n", argv[1]);
	}
  	sorting_algorithms* sa = new sorting_algorithms();

  	sa -> set_array_length(atoi(argv[1]));
  	sa -> new_random_array();
  	// sa -> new_fix_array();
  	// sa -> print_array();
  	if (atoi(argv[2]) == 0)
  	{
  		sa -> insertion_sort();
  	}
  	else if (atoi(argv[2]) == 1)
  	{
  		sa -> merge_sort();
  	}
  	else 
  	{
  		printf("Option not supported\n");
  	}
  	// sa -> print_array();
  	return 0;
}