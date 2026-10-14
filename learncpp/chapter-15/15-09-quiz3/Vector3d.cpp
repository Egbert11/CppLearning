// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 文件：Vector3d.cpp
// 说明：定义 Vector3d 的构造函数与 print()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 备注：本节代码为按原文描述重建。
// ============================================================
#include "Vector3d.h"

#include <iostream>

Vector3d::Vector3d(double x, double y, double z)
	: m_x{ x }, m_y{ y }, m_z{ z }
{
}

void Vector3d::print() const
{
	std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}
