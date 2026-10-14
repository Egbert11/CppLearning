// 来源小节：21.12 Overloading the assignment operator
// 示例说明：Fraction 的 operator= “更好实现”：先做自赋值检查，再逐个成员赋值。
//           对只含非动态成员的类，即使自赋值也无危害，这里的检查只是防御性写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
// 说明：本节代码为按原文描述重建。
// 预期输出：5/3

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

// A better implementation of operator=
Fraction& Fraction::operator= (const Fraction& fraction)
{
    // self-assignment guard
    if (this == &fraction)
        return *this;

    // do the copy
    m_numerator = fraction.m_numerator;     // can handle self-assignment
    m_denominator = fraction.m_denominator; // can handle self-assignment

    // return the existing object so we can chain this operator
    return *this;
}

int main()
{
    Fraction fiveThirds{ 5, 3 };
    Fraction f;
    f = fiveThirds;
    std::cout << f << '\n';

    return 0;
}
