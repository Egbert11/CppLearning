// ============================================================
// 来源小节：14.x Chapter 14 summary and quiz（官方编号 14.x）
// 测验解答：测验 1b——在 Point2d 上增加 distanceTo()，用 <cmath> 的
//           std::sqrt 计算两点间距离。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-14-summary-and-quiz/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <cmath>
#include <iostream>

// --- 原文示例片段（Quiz 1b 解答）---
class Point2d
{
private:
    double m_x{ 0.0 };
    double m_y{ 0.0 };

public:
    Point2d() = default;

    Point2d(double x, double y)
        : m_x{ x }, m_y{ y }
    {
    }

    void print() const
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    double distanceTo(const Point2d& other) const
    {
        return std::sqrt((m_x - other.m_x) * (m_x - other.m_x) + (m_y - other.m_y) * (m_y - other.m_y));
    }
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// Point2d(0, 0)
// Point2d(3, 4)
// Distance between two points: 5
