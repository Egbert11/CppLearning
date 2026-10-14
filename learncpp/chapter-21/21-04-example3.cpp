// 来源小节：21.4 Overloading the I/O operators
// 示例说明：重载 operator<< 以支持 std::cout << point。左操作数是 std::ostream，
//           因此第一个参数是 std::ostream&；必须按引用返回传入的流，才能在一条
//           语句里继续链式 <<。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：Point(2, 3, 4)

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
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')'; // actual output done here

    return out; // return std::ostream so we can chain calls to operator<<
}

int main()
{
    const Point point1 { 2.0, 3.0, 4.0 };

    std::cout << point1 << '\n';

    return 0;
}
