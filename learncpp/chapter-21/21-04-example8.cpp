// 来源小节：21.4 Overloading the I/O operators
// 示例说明：拒绝"语义上无效"的输入——能抽取但值非法的数据（例如负坐标）不会
//           自动让流进入失败态，需要手动 in.setstate(std::ios_base::failbit)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
// 说明：原文该实现为非成员的片段，这里包进完整程序以便编译；片段边界见注释。
//       需要从 stdin 读入，输出随输入而定，例如输入 "-1 2 3" 会被判为失败并重置为 0。

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

// --- 原文示例片段（拒绝负数输入）---
std::istream& operator>> (std::istream& in, Point& point)
{
    double x{};
    double y{};
    double z{};

    in >> x >> y >> z;
    if (x < 0.0 || y < 0.0 || z < 0.0)       // if any extractable input is negative
        in.setstate(std::ios_base::failbit); // set failure mode manually
    point = in ? Point{x, y, z} : Point{};

    return in;
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << "Enter a point: ";

    Point point{ 1.0, 2.0, 3.0 };
    std::cin >> point;

    if (std::cin)
        std::cout << "You entered: " << point << '\n';
    else
        std::cout << "Extraction failed\n";

    return 0;
}
