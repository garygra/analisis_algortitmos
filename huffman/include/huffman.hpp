#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>



using namespace std;
/**
 * @brief 
 * @details 
 */

class dijkstra
{
public:
  /**
   * @brief 
   * @details 
   *
   * @param 
   */
  dijkstra(){
    verbose = false;
  };

  virtual ~dijkstra();

  void get_solution();
  
  void create_adj_mat();

  void print_adj_mat();

  void set_verbose(bool verbose_in){verbose = verbose_in;};
protected:

private:

  bool verbose;
  int mat_size;
  const int inf = 99 ;//1 << 30;
  vector< vector<int> > adj;
  vector<string> labels = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
  vector<int> path;

};


#endif
