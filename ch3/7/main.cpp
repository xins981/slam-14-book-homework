#include <iostream>
#include <Eigen/Geometry>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

int main()
{
    Quaterniond q1 = Quaterniond(0.35, 0.2, 0.3, 0.1); // 小萝卜一号的旋转，用四元数表示
    q1.normalize(); // 归一化四元数
    Vector3d t1 = {0.3, 0.1, 0.1}; // 小萝卜一号的平移
    Quaterniond q2 = Quaterniond(-0.5, 0.4, -0.1, 0.2); // 小萝卜二号的旋转，用四元数表示
    q2.normalize();
    Vector3d t2 = {-0.1, 0.5, 0.3}; // 小萝卜二号的平移
    Vector3d pc1 = {0.5, 0, 0.2}; // 小萝卜一号观察的坐标

    Isometry3d Tcw1 = Isometry3d::Identity(); // 构造世界坐标系到小萝卜一号的变换矩阵
    Tcw1.rotate(q1);
    Tcw1.pretranslate(t1);
    Isometry3d Twc1 = Tcw1.inverse(); // 取逆矩阵，得小萝卜一号到世界坐标系的变换矩阵
    Vector3d pw = Twc1 * pc1; // 进行坐标变换，得向量在世界坐标系下的坐标
    Isometry3d Tcw2 = Isometry3d::Identity(); // 构造世界坐标系到小萝卜二号的变换矩阵
    Tcw2.rotate(q2);
    Tcw2.pretranslate(t2);
    Vector3d pc2 = Tcw2 * pw; // 进行坐标变换，得向量在小萝卜二号的坐标

    cout << "pc2 = " << pc2.transpose() << endl;
    return 0;
}
