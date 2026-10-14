// ============================================================
// 来源小节：23.5 Dependencies
// 示例说明：Point 类与 friend operator<<。Point 本身与 std::ostream
//           无直接关系，但因为 operator<< 用该流输出 Point，所以
//           Point 依赖 std::ostream；程序在调用处依赖 std::cout。
// 原文链接：https://www.learncpp.com/cpp-tutorial/dependencies/
// 预期输出：
//   Point(2, 3, 4)
// 备注：本节代码为按原文描述重建（原 Example 1；原文未给运行输出）。
// ============================================================
#include <iostream>

class Point
{
private:
    double m_x{};
    double m_y{};
    double m_z{};

public:
    Point(double x=0.0, double y=0.0, double z=0.0)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {
    }

    // Point has a dependency on std::ostream here
    friend std::ostream& operator<<(std::ostream& out, const Point& point)
    {
        // Since operator<< is a friend of Point, we can access Point's members directly.
        out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ')';

        return out;
    }
};

int main()
{
    Point point1{ 2.0, 3.0, 4.0 };

    std::cout << point1 << '\n'; // the program has a dependency on std::cout here

    return 0;
}
