// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 文件：main.cpp
// 说明：小测验第 3 步的主程序。依次包含 Vector3d.h 与 Point3d.h，
//       创建 Point3d 与 Vector3d 并演示移动。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 预期输出：
//   Point(1 , 2 , 3)
//   Point(3 , 4 , 0)
// 备注：本节代码为按原文描述重建。
// ============================================================
#include "Vector3d.h"
#include "Point3d.h"

int main()
{
	Point3d p { 1.0, 2.0, 3.0 };
	Vector3d v { 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}
