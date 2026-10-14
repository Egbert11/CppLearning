// 来源小节：21.x Chapter 21 summary and quiz（测验 1 解答）
// 示例说明：针对测验 1 的问题——Point 类的各运算符应实现为“普通/友元函数”还是“成员函数”。
//           a) point + point   → 二元 operator+，不修改左操作数 → 普通/友元函数
//           b) -point          → 一元 operator-      → 成员函数
//           c) std::cout << point → operator<<        → 普通/友元函数
//           d) point = 5       → operator=           → 成员函数
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   (4, 6)
//   (-1, -2)
//   (5, 5)

#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};

public:
    Point(double x = 0.0, double y = 0.0)
        : m_x{ x }
        , m_y{ y }
    {
    }

    // a) binary operator+ : normal/friend (does not modify the left operand)
    friend Point operator+(const Point& p1, const Point& p2)
    {
        return Point{ p1.m_x + p2.m_x, p1.m_y + p2.m_y };
    }

    // b) unary operator- : member
    Point operator-() const
    {
        return Point{ -m_x, -m_y };
    }

    // c) operator<< : normal/friend (required)
    friend std::ostream& operator<<(std::ostream& out, const Point& p)
    {
        out << '(' << p.m_x << ", " << p.m_y << ')';
        return out;
    }

    // d) operator= : must be member
    Point& operator=(double value)
    {
        m_x = value;
        m_y = value;
        return *this;
    }
};

int main()
{
    Point p1{ 1.0, 2.0 };
    Point p2{ 3.0, 4.0 };

    std::cout << p1 + p2 << '\n'; // (4, 6)
    std::cout << -p1 << '\n';     // (-1, -2)

    p1 = 5.0; // calls member operator=
    std::cout << p1 << '\n'; // (5, 5)

    return 0;
}
