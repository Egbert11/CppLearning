// 来源小节：21.4 Overloading the I/O operators
// 示例说明：事务式 operator>> 的变体——抽取失败时把对象重置为默认状态（Point{}）。
//           原文 Author's note 指出：这样失败时"并非什么都不做"，严格意义上已不再是
//           事务式的，或许该叫"不可分操作"（indivisible operation）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
// 说明：原文该实现为非成员的片段，这里包进完整程序以便编译；片段边界见注释。
//       需要从 stdin 读入，输出随输入而定。

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
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';
    return out;
}

// --- 原文示例片段（失败即重置为默认值）---
// note that point must be non-const so we can modify the object
// note that this implementation is a non-friend
std::istream& operator>> (std::istream& in, Point& point)
{
    double x{};
    double y{};
    double z{};

    in >> x >> y >> z;
    point = in ? Point{x, y, z} : Point{};

    return in;
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << "Enter a point: ";

    Point point{ 1.0, 2.0, 3.0 };
    std::cin >> point;

    std::cout << "You entered: " << point << '\n';

    return 0;
}
