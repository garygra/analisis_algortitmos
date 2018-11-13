#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define I 8
#define J 9


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
