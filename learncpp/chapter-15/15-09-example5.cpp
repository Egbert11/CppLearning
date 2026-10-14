// ============================================================
// 来源小节：15.9 Friend classes and friend member functions
// 示例说明：小测验的起始代码（对应测验"初始程序"）。Vector3d 与 Point3d
//           都各自私有三个坐标并有 print()；Point3d::moveByVector() 暂为空，
//           留待后面三个步骤实现。
// 原文链接：https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/
// 预期输出：
//   Point(1 , 2 , 3)
//   Point(1 , 2 , 3)
//   （此时 moveByVector 还没实现，所以两次打印相同）
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
		// 稍后实现
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
