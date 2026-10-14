// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 文件：Vector3d.h
// 说明：为了把 Point3d::moveByVector 声明为友元，需先包含 Point3d.h
//       以获得其完整定义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 备注：本节代码为按原文描述重建。
// ============================================================
#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3d.h" // 为了把 Point3d::moveByVector() 声明为友元

class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0);

	void print() const;

	friend void Point3d::moveByVector(const Vector3d& v);
};

#endif
