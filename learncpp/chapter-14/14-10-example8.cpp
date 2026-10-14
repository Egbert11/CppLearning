// ============================================================
// 来源小节：14.10 Constructor member initializer lists
// 示例说明：当异常不可用/不希望用时，用友元工厂函数返回 std::optional<Fraction>，
//           间接使用私有构造函数，以返回空 optional 表示失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
// 备注：本节代码为按原文描述忠实重建（原文给出完整代码）。
// ============================================================
#include <iostream>
#include <optional>

// --- 原文示例片段（原 Example 9）---
class Fraction
{
private:
    int m_numerator { 0 };
    int m_denominator { 1 };

    // private constructor can't be called by public
    Fraction(int numerator, int denominator):
        m_numerator { numerator }, m_denominator { denominator }
    {
    }

public:
    // Allow this function to access private members
    friend std::optional<Fraction> createFraction(int numerator, int denominator);
};

std::optional<Fraction> createFraction(int numerator, int denominator)
{
    if (denominator == 0)
        return {};

    return Fraction{numerator, denominator};
}

int main()
{
    auto f1 { createFraction(0, 1) };
    if (f1)
    {
        std::cout << "Fraction created\n";
    }

    auto f2 { createFraction(0, 0) };
    if (!f2)
    {
        std::cout << "Bad fraction\n";
    }

    return 0;
}

// 预期输出：
// Fraction created
// Bad fraction
