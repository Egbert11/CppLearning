// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 示例说明：小测验第 2 步解答——只把单个成员函数 Point3d::moveByVector
//           设为 Vector3d 的友元（而不是整个类）。写法要点：
//           1) 先前向声明 class Vector3d;
//           2) Point3d 里只声明 moveByVector（不内联定义，因为 Vector3d 不完整）
//           3) 完整定义 Vector3d，其中 friend void Point3d::moveByVector(...)
//           4) 最后在 Vector3d 定义之后，定义 Point3d::moveByVector
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 预期输出：
//   Point(1 , 2 , 3)
//   Point(3 , 4 , 0)
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

class Vector3d; // Vector3d 的前向声明

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{
	}

	void print() const
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	void moveByVector(const Vector3d& v); // 只声明，稍后定义
};

class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{
	}

	void print() const
	{
		std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	// 只把 Point3d::moveByVector 这一个成员函数设为友元
	friend void Point3d::moveByVector(const Vector3d& v);
};

// 现在定义 Point3d::moveByVector（Vector3d 已完整定义，可访问其私有成员）
void Point3d::moveByVector(const Vector3d& v)
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

int main()
{
	Point3d p { 1.0, 2.0, 3.0 };
	Vector3d v { 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}
