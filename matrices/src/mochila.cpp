#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace Eigen;
using namespace std;


int main()
{
  int W_max = 10;
  int vecs_size = 5;
  // int vecs_size = 12;
  VectorXd w(vecs_size);
  VectorXd v(vecs_size);
  w <<  6, 5, 3, 2, 2;
  v << 10, 9, 8, 7, 3;
  // w << 11,  7,  5, 4,  3,  3,  3,  2, 2, 2, 2,  1;
  // v << 20, 10, 11, 5, 25, 50, 15, 12, 6, 4, 5, 30;
  MatrixXd m = MatrixXd::Constant(w.size() + 1, W_max + 1, 0);
  for (int i = 1; i < m.rows(); ++i)
  {
    for (int j = 0; j < m.cols(); ++j)
    {
      if (w[i-1] > j)
      {
        m(i, j) = m(i-1, j);
      }
      else 
      {
        m(i, j) = max(m(i-1, j), m(i-1, j-w[i-1]) + v[i-1]);
      }
    }
  }
  cout << "El valor de la solución es: " << m(w.size(), W_max) << endl;
  cout << "La solución es: " << endl;
  int w_aux = W_max;
  for (int i = v.size(); i > 0; --i)
  {
    if (m(i,w_aux) != m(i-1, w_aux))
    {
      cout << "\t" << i ;
      w_aux -= w(i-1);
    }
  }
  cout << endl;
}