#include "dijkstra.hpp"

using namespace std;

dijkstra::~dijkstra()
{
}


void dijkstra::create_adj_mat()
{

  mat_size = 10;
  adj = vector< vector<int> > (mat_size); 
  for (int i = 0; i < mat_size; ++i)
  {
    adj[i] = vector<int>(mat_size);
    for (int j = 0; j < mat_size; ++j)
    {
      adj[i][j] = inf;
    }
  }

  adj[A][B] = 2;
  adj[A][C] = 4;
  adj[A][D] = 3;
  adj[B][E] = 7;
  adj[B][G] = 6;
  adj[C][E] = 3;
  adj[C][F] = 2;
  adj[C][G] = 4;
  adj[D][E] = 4;
  adj[D][F] = 1;
  adj[D][G] = 5;
  adj[E][H] = 1;
  adj[E][I] = 4;
  adj[F][I] = 3;
  adj[G][H] = 3;
  adj[G][I] = 3;
  adj[H][J] = 3;
  adj[I][J] = 4;

  // adj[B][A] = 2;
  // adj[C][A] = 4;
  // adj[D][A] = 3;
  // adj[E][B] = 7;
  // adj[G][B] = 6;
  // adj[E][C] = 3;
  // adj[F][C] = 2;
  // adj[G][C] = 4;
  // adj[E][D] = 4;
  // adj[F][D] = 1;
  // adj[G][D] = 5;
  // adj[H][E] = 1;
  // adj[I][E] = 4;
  // adj[I][F] = 3;
  // adj[H][G] = 3;
  // adj[I][G] = 3;
  // adj[J][H] = 3;
  // adj[J][I] = 4;

}


void dijkstra::print_adj_mat()
{
  cout << "  [ " ;
  
  for (int i = 0; i < mat_size; ++i)
  {
    cout << labels[i]  << " ";
  }
  cout << "]" << endl;

  for (int i = 0; i < mat_size; ++i)
  {
    stringstream ss;
    ss << " ";
    cout << labels[i] << " [ ";
    for (int j = 0; j < mat_size; ++j)
    {
      printf("%*d ", 2, adj[i][j]);
    }
    printf("]\n");
  }

}

void dijkstra::get_solution()
{
  int A_mat = A;
  int B_mat = J;
  int u = -1;
  double min_dist = inf;
  double alt;
  vector<double> dist(mat_size);
  vector<double> prev(mat_size);
  vector<bool> visitados(mat_size);
  int not_visited = mat_size;
  int num_visited = 0;

  for (int i = 0; i < mat_size; ++i)
  {
    dist[i] = inf;   
    prev[i] = -1; 
    visitados[i] = false;
  }
  dist[A_mat] = 0;

  while (not_visited != 0 && num_visited < mat_size)
  { 
    if (verbose) cout << "num_visited: " << num_visited << "\tnot_visited: " << not_visited << endl;
    min_dist = inf;
    for (int it = 0; it < mat_size; ++it)
    {
      if (visitados[it] == false && dist[it] <  min_dist)
      {
        if (verbose) cout << "dist[it]: " << dist[it] << " min_dist: " << min_dist << " u: "<< u << " it: " << it  << endl;
        u = it;
        min_dist = dist[it];
      }

    }
    if (verbose) cout << "Start: " << A_mat<< "\tEnd: " << B_mat << "\tu: "<< u << endl;
    if (u == B_mat)
    { 
      not_visited = 0;

    } else {
      visitados[u] = true;
      num_visited++;

      for (int v = 0; v < mat_size; ++v)
      {
        if(v != u)
        {
          alt = dist[u] + adj[u][v];
          if (verbose) cout << "dist[v]: " << dist[v] << " alt: " << alt << " u: "<< u << " v: " << v << endl;
          if(alt < dist[v])
          {
            dist[v] = alt;
            prev[v] = u;
          }
        }

      }
    }
    if (verbose)
    {
      cout << "prev is:" << endl;
      for (int i = 0; i < prev.size(); ++i)
      {
        cout << prev[i] << " ";
      }
      cout << endl;

      cout << "dist is:" << endl;
      for (int i = 0; i < dist.size(); ++i)
      {
        cout << dist[i] << " ";
      }
      cout << endl;

      cout << "==========================" << endl;
    }
  }

  u = B_mat;

  if(verbose) cout << "Path is: " << endl;
  while (u != -1)
  {
    if(verbose) cout << "\t" << u;

    path.push_back(u);
    u = prev[u];
  }

  cout << "The path is: " << endl;
  int total_cost = 0;
  for (int i = path.size() -1 ; i > 0; --i)
  {
    cout << "\tFrom: " << labels[path[i]] << "\tto: " << labels[path[i-1]] << "\tCost: " << adj[path[i]][path[i-1]] << endl;
    total_cost += adj[path[i]][path[i-1]];
  }
  cout << "\tThe total cost is: " << total_cost << endl;


  if(verbose) cout << "\nEnded" << endl; 
}

