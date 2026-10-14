// 来源小节：21.6 Overloading unary operators +, -, and !（Quiz 解答）
// 示例说明：一元 operator+ ——它返回操作数本身（不会把负数变正）。原文给出两种等价写法：
//             Point operator+() const { return { m_x, m_y, m_z }; }
//             Point operator+() const { return *this; }
//           这里采用第二种，并按原文说明"结果按值返回"（调用者可能想修改返回对象）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-unary-operators/
// 说明：本节代码为按原文描述重建（原文只给片段）。预期输出：
//   (2, 3, 4)
//   (-2, -3, -4)

#include <iostream>

class Point
{
private:
    double m_x {};
    double m_y {};
    double m_z {};

public:
    Point(double x=0.0, double y=0.0, double z=0.0):
        m_x{x}, m_y{y}, m_z{z}
    {
    }

    // Convert a Point into its negative equivalent
    Point operator- () const { return { -m_x, -m_y, -m_z }; }

    // Return the operand unchanged (unary plus does NOT make a negative value positive)
    Point operator+ () const { return *this; }

    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getZ() const { return m_z; }
};

std::ostream& operator<<(std::ostream& out, const Point& p)
{
    out << '(' << p.getX() << ", " << p.getY() << ", " << p.getZ() << ')';
    return out;
}

int main()
{
    const Point point{ 2.0, 3.0, 4.0 };

    std::cout << (+point) << '\n'; // unary plus returns the operand unchanged
    std::cout << (-point) << '\n'; // unary minus negates

    return 0;
}
