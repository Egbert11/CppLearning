// ============================================================
// 来源小节：14.11 Default constructors and default arguments
// 示例说明：Fraction 同时提供 Fraction() = default 与两参构造函数，
//           默认构造出的对象是合理值 0/1（而非未初始化）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 10）---
class Fraction
{
private:
    int m_numerator { 0 };
    int m_denominator { 1 };

public:
    Fraction() = default; // default constructor: uses the default member initializers

    Fraction(int numerator, int denominator)
        : m_numerator { numerator }, m_denominator { denominator }
    {
    }

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

int main()
{
    Fraction f1{ 3, 5 };
    f1.print();

    Fraction f2{}; // 0/1
    f2.print();

    return 0;
}

// 预期输出：
// 3/5
// 0/1
