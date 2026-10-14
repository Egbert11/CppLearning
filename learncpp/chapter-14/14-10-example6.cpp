// ============================================================
// 来源小节：14.10 Constructor member initializer lists
// 示例说明：Fraction 的类不变式——分母不能为 0。用成员初始化列表初始化分子分母。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
// 备注：本节代码为按原文描述忠实重建。原文此例只是一个类定义片段，
//       这里补一个 main 以便编译运行。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 7）---
class Fraction
{
private:
    int m_numerator {};
    int m_denominator {};

public:
    Fraction(int numerator, int denominator):
        m_numerator { numerator }, m_denominator { denominator }
    {
    }

    int numerator() const { return m_numerator; }
    int denominator() const { return m_denominator; }
};

int main()
{
    Fraction f{ 3, 5 }; // 3/5 —— 合法的分母
    std::cout << f.numerator() << '/' << f.denominator() << '\n';

    return 0;
}

// 预期输出：
// 3/5
