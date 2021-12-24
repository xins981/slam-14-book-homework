#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    Matrix4d m;
    m << 1, 2, 3, 4,
         5, 6, 7, 8,
         9, 10, 11, 12,
         13, 14, 15, 16;
    cout << "m = " << endl;
    cout << m << endl;
    Matrix3d b = m.block<3, 3>(0, 0);
    cout << "matrix of left corner 3 by 3 = " << endl;
    cout << b << endl;
    return 0;
}
