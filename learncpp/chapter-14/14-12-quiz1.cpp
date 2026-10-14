// ============================================================
// 来源小节：14.12 Delegating constructors
// 示例说明：测验 1 解答——Ball 用 4 个独立构造函数（默认、仅半径、仅颜色、颜色+半径），
//           每个都调用 print()。缺陷：各构造函数重复了默认值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/delegating-constructors/
// 备注：本节代码为按原文描述忠实重建（原文给出完整解答）。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文测验 1 解答 ---
class Ball
{
private:
    std::string m_color { "black" };
    double m_radius { 10.0 };

public:
    Ball()
    {
        print();
    }

    Ball(double radius)
        : m_radius { radius }
    {
        print();
    }

    Ball(std::string_view color)
        : m_color { color }
    {
        print();
    }

    Ball(std::string_view color, double radius)
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
