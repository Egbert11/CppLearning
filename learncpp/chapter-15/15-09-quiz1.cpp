// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 示例说明：小测验第 1 步解答——把 Point3d 设为 Vector3d 的"友元类"，并在
//           Point3d::moveByVector() 中把向量各分量加到点坐标上：
//           m_x += v.m_x; m_y += v.m_y; m_z += v.m_z;
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 预期输出：
//   Point(1 , 2 , 3)
//   Point(3 , 4 , 0)
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

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

	// Point3d 是本类的友元，因此 Point3d::moveByVector 可以访问私有成员
	friend class Point3d;
};

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

	void moveByVector(const Vector3d& v)
	{
		m_x += v.m_x;
		m_y += v.m_y;
		m_z += v.m_z;
	}
};

int main()
{
	Point3d p { 1.0, 2.0, 3.0 };
	Vector3d v { 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}
