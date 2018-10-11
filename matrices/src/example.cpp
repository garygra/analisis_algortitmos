#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{

  cout << "SIZE AT RUN TIME" << endl;
  MatrixXd m_rt = MatrixXd::Random(3,3);
  m_rt = (m_rt + MatrixXd::Constant(3,3,1.2)) * 50;
  cout << "m_rt =" << endl << m_rt << endl;
  VectorXd v_rt(3);
  v_rt << 1, 2, 3;
  cout << "m_rt * v_rt =" << endl << m_rt * v_rt << endl;

  cout << "SIZE AT COMPILE TIME" << endl;
  Matrix3d m_ct = Matrix3d::Random();
  m_ct = (m_ct + Matrix3d::Constant(1.2)) * 50;
  cout << "m_ct =" << endl << m_ct << endl;
  Vector3d v_ct(1,2,3);
  cout << "m_ct * v_ct =" << endl << m_ct * v_ct << endl;

  cout << "USING THE * OPERATOR" << endl;
  Matrix2d m1_oper;
  m1_oper << 2, 3,
  			3, 5 ;
  Matrix2d m2_oper;
  m2_oper << 1, 2,
  			5,-1 ;
  cout << m1_oper * m2_oper << endl;

  cout << "TRANSPOSE MATRIX" << endl;
  cout << m2_oper.transpose() << endl;
 
  cout << "DOT PRODUCT / CROSS PRODUCT" << endl;
  Vector3d v(1,2,3);
  Vector3d w(0,1,2);
  cout << "Dot product: " << v.dot(w) << endl;
  double dp = v.adjoint()*w; // automatic conversion of the inner product to a scalar
  cout << "Dot product via a matrix product: " << dp << endl;
  cout << "Cross product:\n" << v.cross(w) << endl;

  cout << "Here is mat.sum():       " << m1_oper.sum()       << endl;
  cout << "Here is mat.prod():      " << m1_oper.prod()      << endl;
  cout << "Here is mat.mean():      " << m1_oper.mean()      << endl;
  cout << "Here is mat.minCoeff():  " << m1_oper.minCoeff()  << endl;
  cout << "Here is mat.maxCoeff():  " << m1_oper.maxCoeff()  << endl;
  cout << "Here is mat.trace():     " << m1_oper.trace()     << endl;
}