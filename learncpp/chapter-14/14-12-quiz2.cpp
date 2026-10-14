// ============================================================
// 来源小节：14.12 Delegating constructors
// 示例说明：测验 2 解答——用委托构造把 Ball 缩减为 2 个构造函数：
//           Ball(double radius) 委托给 Ball{ "black", radius }，
//           另一构造函数用默认实参处理颜色和/或半径。
// 原文链接：https://www.learncpp.com/cpp-tutorial/delegating-constructors/
// 备注：本节代码为按原文描述忠实重建（原文给出完整解答）。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文测验 2 解答 ---
class Ball
{
private:
    std::string m_color { "black" };
    double m_radius { 10.0 };

public:
    Ball(double radius)
        : Ball { "black", radius } // delegate to the two-argument constructor
    {
        // no need to call print() here: the delegated constructor does it
    }

    Ball(std::string_view color = "black", double radius = 10.0)
        : m_color { color }, m_radius { radius }
    {
        print();
    }

    void print() const
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}

// 预期输出：
// Ball(black, 10)
// Ball(blue, 10)
// Ball(black, 20)
// Ball(blue, 20)
