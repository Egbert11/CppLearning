// 来源小节：21.12 Overloading the assignment operator
// 示例说明：因为 operator= 返回 *this，可以链式赋值 f1 = f2 = f3。C++ 也允许对自身赋值
//           f1 = f1；对只做成员逐个复制的 Fraction 而言，自赋值只是浪费，无危害。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：9/5

#include <cassert>
#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }
        , m_denominator{ denominator }
    {
        assert(denominator != 0);
    }

    Fraction& operator= (const Fraction& fraction);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

Fraction& Fraction::operator= (const Fraction& fraction)
{
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;
    return *this;
}

int main()
{
    Fraction f1 { 5, 3 };
    Fraction f2 { 7, 2 };
    Fraction f3 { 9, 5 };

    f1 = f2 = f3; // chained assignment
    std::cout << f1 << '\n'; // prints 9/5

    f1 = f1; // self-assignment (harmless here: no dynamic memory involved)

    return 0;
}
