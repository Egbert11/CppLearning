// 来源小节：21.5 Overloading operators using member functions
// 示例说明：为什么 operator<< 不能写成成员——它的左操作数是 std::ostream，而标准库
//           类不允许被修改，所以只能写成（非成员的）友元函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-operators-using-member-functions/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：Point(2, 3, 4)

#include <iostream>

class Point
{
private:
    double m_x {};
    double m_y {};
    double m_z {};

public:
    Point(double x=0.0, double y=0.0, double z=0.0)
        : m_x { x }, m_y { y }, m_z { z }
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

    return out;
}

int main()
{
    Point point1 { 2.0, 3.0, 4.0 };

    std::cout << point1;

    return 0;
}
