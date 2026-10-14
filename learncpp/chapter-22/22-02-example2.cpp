// ============================================================
// 来源小节：22.2 R-value references
// 示例说明：右值引用延长临时对象的生命周期——auto&& 绑定到临时 Fraction，
//           该临时对象会一直存活到引用离开作用域。
// 原文链接：https://www.learncpp.com/cpp-tutorial/rvalue-references/
// 预期输出：
//   3/5
// 备注：本节代码为按原文描述重建（原 Example 2）。
// ============================================================
#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
    {
        out << f1.m_numerator << '/' << f1.m_denominator;
        return out;
    }
};

int main()
{
    auto&& rref{ Fraction{ 3, 5 } }; // r-value reference to temporary Fraction

    // f1 of operator<< binds to the temporary, no copies are created.
    std::cout << rref << '\n';

    return 0;
} // rref (and the temporary Fraction) goes out of scope here
