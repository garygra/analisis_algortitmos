#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace Eigen;
using namespace std;

const int ROWS = 4;
const int COLS = 7;

MatrixXd get_next_table(MatrixXd last, vector<string> vars, vector<string>* out_vars)
{
  int min_z_row, min_z_col;
  int min_t_row, min_t_col;
  float min_z = (last.row(ROWS - 1)).minCoeff(&min_z_col, &min_z_row);

  VectorXd v_aux_t = last.col(COLS - 1);
  VectorXd col_sel = last.col(min_z_row);
  float min_t = (v_aux_t.transpose().array() * 
    col_sel.transpose().cwiseInverse().array()).head(ROWS - 1).pow(2).sqrt()
    .minCoeff(&min_t_col, &min_t_row);

  MatrixXd m_aux = MatrixXd::Constant(ROWS, COLS, 0);

  m_aux.row(min_t_row) =  last.row(min_t_row).transpose()  * last.row(min_t_row).col(min_z_row).cwiseInverse() ;
  
  (*out_vars)[min_t_row] = vars[min_z_row];

  VectorXd hx = VectorXd::Constant(COLS, 0);

  for (int i = 0; i < ROWS; ++i)
  {
    if (min_t_row != i)
    {
      hx = VectorXd::Constant(COLS, 0);
      hx = last.row(i) - col_sel(i) * m_aux.row(min_t_row);
      m_aux.row(i) = hx;
    }
  }

  return m_aux;
}

int main()
{
  MatrixXd m = MatrixXd::Constant(ROWS, COLS, 0);

  // // Ej. 1
  // m <<   2,   3, 1, 0, 0, 25,
  //        4,   1, 0, 1, 0, 32,
  //        2,   9, 0, 0, 1, 54,
  //      -24, -31, 0, 0, 0, 0;
  // vector<string> vars = {"x", "y"};

  // Ej. 2
  m <<  2.0, 1.0,  0.0, 1.0, 0.0, 0.0, 10.0,
        1.0, 2.0, -2.0, 0.0, 1.0, 0.0, 20.0,
        0.0, 1.0,  2.0, 0.0, 0.0, 1.0,  5.0,
       -2.0, 1.0, -2.0, 0.0, 0.0, 0.0,  0.0;
  vector<string> vars = {"x1", "x2", "x3"};

  int in_vars = vars.size();

  for (int i = 0; i <= COLS - vars.size(); ++i)
  {
    stringstream ss ;
    ss << "h" << i + 1;
    vars.push_back(ss.str());
  }
  cout << "Using the variables:\n";
  for (int i = 0; i < vars.size(); ++i)
  {
    cout << vars[i] << "\t";
  }
  cout << endl;

  vector<string> out_vars(ROWS);
  int iter = 0;
  while (m.row(ROWS-1).minCoeff() < 0)
  {
    m = get_next_table(m, vars, &out_vars);
    cout << "=======================" << endl;
    cout << "T" << iter << ":" << endl;
    cout << m << endl;
    iter++;
  }  
  cout << "=======================" << endl;

  cout << "The best policy is:";
  int j;
  for (int i = 0; i < in_vars; ++i)
  { 
    j = 0;
    while(j < out_vars.size() && vars[i] != out_vars[j])
    {
      j++;
    }
    if (j < out_vars.size())
    {
      cout << "\n\t" << vars[i] << " = " << m.col(COLS-1).row(j);
    }
  } 
  cout << "\n\t with a value of: " << m(ROWS - 1, COLS - 1) << endl;

}