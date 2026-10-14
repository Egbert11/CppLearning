// ============================================================
// 来源小节：23.2 Composition
// 示例说明：Fraction 类——分子与分母是"组合"关系的部分：
//           它们只属于该 Fraction 对象，随其创建、随其销毁。
// 原文链接：https://www.learncpp.com/cpp-tutorial/composition/
// 预期输出：
//   Fraction: 3/4
// 备注：本节代码为按原文描述重建（原 Example 1）。
// ============================================================
#include <iostream>

class Fraction
{
private:
    int m_numerator{};
    int m_denominator{};

public:
    // Constructor
    Fraction(int numerator=0, int denominator=1)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    int getNumerator() const { return m_numerator; }
    int getDenominator() const { return m_denominator; }
};

int main()
{
    Fraction f{ 3, 4 };
    std::cout << "Fraction: " << f.getNumerator() << '/' << f.getDenominator() << '\n';
    return 0;
}
