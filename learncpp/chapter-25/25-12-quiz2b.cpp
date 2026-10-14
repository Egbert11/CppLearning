// ---------------------------------------------------------------------------
// 来源小节：25.x Chapter 25 summary and quiz（官方编号 25.x，本仓库顺延为 25.12）
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-25-summary-and-quiz/
// 测验题：Q2b —— 让 Shape（Q2a 定义的抽象类）派生出 Triangle 与 Circle，
//         重写 print()，使给定 main 输出下面结果。
// 预期输出：
//   Circle(Point(1, 2), radius 7)
//   Triangle(Point(1, 2), Point(3, 4), Point(5, 6))
// 代码为原文逐字提取（Shape 定义即 Q2a 的解；Point 为原文提供的示例类）。
// ---------------------------------------------------------------------------

#include <iostream>

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Shape
{
public:
	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, const Shape& p)
	{
		return p.print(out);
	}
	virtual ~Shape() = default;
};

class Triangle : public Shape
{
private:
	Point m_p1;
	Point m_p2;
	Point m_p3;

public:
	Triangle(const Point& p1, const Point& p2, const Point& p3)
		: m_p1{ p1 }, m_p2{ p2 }, m_p3{ p3 }
	{
	}

	std::ostream& print(std::ostream& out) const override
	{
		return out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ')';
	}
};

class Circle : public Shape
{
private:
	Point m_center;
	int m_radius;

public:
	Circle(const Point& center, int radius)
		: m_center{ center }, m_radius{ radius }
	{
	}

	std::ostream& print(std::ostream& out) const override
	{
		return out << "Circle(" << m_center << ", radius " << m_radius << ')';
	}
};

int main()
{
	Circle c{ Point{ 1, 2 }, 7 };
	std::cout << c << '\n';

	Triangle t{ Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 } };
	std::cout << t << '\n';

	return 0;
}
