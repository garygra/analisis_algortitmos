#ifndef SORTING_ALGORITHMS_HPP
#define SORTING_ALGORITHMS_HPP

#include "timer.hpp"
#include <iostream>
#include <math.h>

#define MIN_INTEGER 0
#define MAX_INTEGER 1000
/**
 * @brief 
 * @details 
 */
class sorting_algorithms
{
public:
	/**
	 * @brief 
	 * @details 
	 *
	 * @param 
	 */
  sorting_algorithms(){
    srand(231192);
  };

  virtual ~sorting_algorithms();

  void set_array_length(int length_in);

  void new_random_array();

  void insertion_sort();

  void merge_sort();

  void print_array();

  void new_fix_array();


protected:

private:

  int *array;
  int size_arr;

  sys_timer_t timer;

  double uniform_random();


  int uniform_int_random(int min, int max);

  void print_array(int arr[], int size);

};


#endif