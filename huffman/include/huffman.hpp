#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include <assert.h>  

#include "priority_queue.hpp"

using namespace std;
/**
 * @brief 
 * @details 
 */

class huffman
{
public:
  /**
   * @brief 
   * @details 
   *
   * @param 
   */
  huffman();

  priority_queue queue;

  virtual ~huffman();

  void get_solution();
  
  void initialize(vector<char> vec_chars_in, vector<int> vec_frecs_in);

  void print_sol();

  void next_branch(int val, node_h* n);

  void print_vector();


protected:

private:


};


#endif
