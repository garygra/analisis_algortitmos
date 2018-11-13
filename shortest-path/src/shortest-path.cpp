#include <iostream>
#include "dijkstra.hpp"

int main (int argc, char *argv[])
{
  dijkstra* dj = new dijkstra();
  
  cout << "creating adj matrix" << endl;
  dj -> create_adj_mat();

  cout << "printing adj matrix" << endl;
  dj -> print_adj_mat();
  
  cout << "getting solution" << endl;
  dj -> get_solution();

  return 0;
}