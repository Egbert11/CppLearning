// 来源小节：21.4 Overloading the I/O operators
// 示例说明：返回流引用使链式输出成为可能——cout << point1 << ' ' << point2 << '\n'
//           先算 (cout << point1) 得到流引用，再继续 <<。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：Point(2, 3.5, 4) Point(6, 7.5, 8)

#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0)
      : m_x{x}, m_y{y}, m_z{z}
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
}

int main()
{
    Point point1 { 2.0, 3.5, 4.0 };
    Point point2 { 6.0, 7.5, 8.0 };

    std::cout << point1 << ' ' << point2 << '\n';

    return 0;
}
