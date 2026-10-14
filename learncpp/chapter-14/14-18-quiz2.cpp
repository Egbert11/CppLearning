// ============================================================
// 来源小节：14.x Chapter 14 summary and quiz（官方编号 14.x）
// 测验解答：测验 2——把 13.10 课的 Fraction struct 改写成类，所有函数
//           变为非静态成员函数；构造函数显式 explicit（见测验 3 讨论）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-14-summary-and-quiz/
// 备注：本节代码为按原文描述忠实重建。
//       原文注明：本测验不符合"何时该用成员/非成员函数"的最佳实践，
//       其目的是练习把非成员函数改写为成员函数。
// ============================================================
#include <iostream>

// --- 原文示例片段（Quiz 2 解答）---
class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    explicit Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    void getFraction()
    {
        std::cout << "Enter a value for numerator: ";
        std::cin >> m_numerator;
        std::cout << "Enter a value for denominator: ";
        std::cin >> m_denominator;
        std::cout << '\n';
    }

    Fraction multiply(const Fraction& f2) const
    {
        return Fraction{ m_numerator * f2.m_numerator, m_denominator * f2.m_denominator };
    }

    void printFraction() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

int main()
{
    Fraction f1{};
    f1.getFraction();

    Fraction f2{};
    f2.getFraction();

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).printFraction();

    return 0;
}
// --- 原文示例片段结束 ---

// 示例运行（输入 2 3 4 5 时）：
// Enter a value for numerator: 2
// Enter a value for denominator: 3
//
// Enter a value for numerator: 4
// Enter a value for denominator: 5
//
// Your fractions multiplied together: 8/15
