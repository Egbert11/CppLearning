// 来源小节：21.4 Overloading the I/O operators
// 示例说明：Point 只有 getter，没有重载 operator<< 时的打印方式——必须为每个成员
//           分别写一次 <<，既啰嗦又容易出错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
// 说明：本节代码取自原文（逐字保留）。
// 预期输出：Point(5, 6, 7)

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
};

int main()
{
    // --- 原文示例片段 ---
    Point point { 5.0, 6.0, 7.0 };

    std::cout << "Point(" << point.getX() << ", " <<
        point.getY() << ", " <<
        point.getZ() << ')';
    // --- 原文示例片段结束 ---

    std::cout << '\n';
    return 0;
}
