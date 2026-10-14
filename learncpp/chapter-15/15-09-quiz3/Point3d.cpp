// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 文件：Point3d.cpp
// 说明：定义 Point3d 的构造函数、print() 与 moveByVector()。因为要访问
//       Vector3d 的成员，所以除了 Point3d.h 还需包含 Vector3d.h。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 备注：本节代码为按原文描述重建。
// ============================================================
#include "Point3d.h"
#include "Vector3d.h" // moveByVector() 的参数类型

#include <iostream>

Point3d::Point3d(double x, double y, double z)
	: m_x{ x }, m_y{ y }, m_z{ z }
{
}

void Point3d::print() const
{
	std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}

void Point3d::moveByVector(const Vector3d& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}
