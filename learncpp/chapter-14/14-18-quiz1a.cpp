// ============================================================
// 来源小节：14.x Chapter 14 summary and quiz（官方编号 14.x）
// 测验解答：测验 1a——实现 Point2d 类：两个默认 0.0 的 double 成员、
//           一个构造函数，以及打印 "Point2d(x, y)" 的 print()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-14-summary-and-quiz/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（Quiz 1a 解答）---
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
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // 应提供两个实参，这行会编译错误

    first.print();
    second.print();

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// Point2d(0, 0)
// Point2d(3, 4)
