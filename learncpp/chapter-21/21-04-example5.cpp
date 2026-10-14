// 来源小节：21.4 Overloading the I/O operators
// 示例说明：为 Point 增加 operator>>。此版本直接把数据抽取到成员里，存在"部分抽取"
//           问题：一旦某次抽取失败，流进入失败态，后续抽取不再进行，于是对象里
//           一半是新值、一半是旧值（或 0），形成"混合体"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
// 说明：本节代码取自原文（逐字保留）。本程序需要从 stdin 读入，输出随输入而定：
//   - 输入 "4.0 5.6 7.26"  → You entered: Point(4, 5.6, 7.26)
//   - 输入 "4.0b 5.6 7.26" → You entered: Point(4, 0, 3)   ← 部分抽取造成的坏结果

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
    friend std::istream& operator>> (std::istream& out, Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

    return out;
}

// note that point must be non-const so we can modify the object
std::istream& operator>> (std::istream& in, Point& point)
{
    // This version subject to partial extraction issues (see below)
    in >> point.m_x >> point.m_y >> point.m_z;

    return in;
}

int main()
{
    std::cout << "Enter a point: ";

    Point point{ 1.0, 2.0, 3.0 }; // non-zero test data
    std::cin >> point;

    std::cout << "You entered: " << point << '\n';

    return 0;
}
