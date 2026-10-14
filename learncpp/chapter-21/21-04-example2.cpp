// 来源小节：21.4 Overloading the I/O operators
// 示例说明：把打印封装进 print() 成员函数更好复用，但因为返回 void，它无法穿插在
//           一条输出语句中间——输出不得不拆成多条语句。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：My point is: Point(5, 6, 7) in Cartesian space.

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

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }

    void print() const
    {
        std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ')';
    }
};

int main()
{
    const Point point { 5.0, 6.0, 7.0 };

    std::cout << "My point is: ";
    point.print();
    std::cout << " in Cartesian space.\n";

    return 0;
}
