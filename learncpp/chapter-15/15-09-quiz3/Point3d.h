// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 文件：Point3d.h
// 说明：小测验第 3 步——把第 2 步拆成多文件。Point3d 前向声明 Vector3d，
//       并只声明 moveByVector（不内联定义）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 备注：本节代码为按原文描述重建。
// ============================================================
#ifndef POINT3D_H
#define POINT3D_H

class Vector3d; // 为函数参数 moveByVector() 前向声明 class Vector3d

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0);

	void print() const;

	void moveByVector(const Vector3d& v); // 上面的前向声明对这里的引用参数已足够
};

#endif
