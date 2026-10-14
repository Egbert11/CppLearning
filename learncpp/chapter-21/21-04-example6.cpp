// 来源小节：21.4 Overloading the I/O operators
// 示例说明：事务式（transactional）operator>>——先把值抽取到临时变量，只有全部成功
//           才一次性写回对象；否则对象保持不变（要么完全成功，要么完全不变）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
// 说明：原文该实现为非成员的片段，这里包进完整程序以便编译；片段边界见注释。
//       需要从 stdin 读入，输出随输入而定，例如输入 "4.0 5.6 7.26"
//       → You entered: Point(4, 5.6, 7.26)。

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

    friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';
    return out;
}

// --- 原文示例片段（事务式 operator>>）---
// note that point must be non-const so we can modify the object
// note that this implementation is a non-friend
std::istream& operator>> (std::istream& in, Point& point)
{
    double x{};
    double y{};
    double z{};

    if (in >> x >> y >> z)      // if all extractions succeeded
        point = Point{x, y, z}; // overwrite our existing point

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
