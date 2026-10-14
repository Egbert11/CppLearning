// 来源小节：21.12 Overloading the assignment operator
// 示例说明：Fraction 重载 operator=，把已有对象的成员逐个赋成源对象的值，并返回 *this
//           以便链式赋值。它是成员函数，且只用一个参数。main 里 f = fiveThirds 调用它。
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
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }
        , m_denominator{ denominator }
    {
        assert(denominator != 0);
    }

    // Copy constructor
    Fraction(const Fraction& fraction)
        : m_numerator{ fraction.m_numerator }
        , m_denominator{ fraction.m_denominator }
    {
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    // Overloaded assignment
    Fraction& operator= (const Fraction& fraction);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

// A simplistic implementation of operator= (see better implementation below)
Fraction& Fraction::operator= (const Fraction& fraction)
{
    // do the copy
    m_numerator = fraction.m_numerator;
    m_denominator = fraction.m_denominator;

    // return the existing object so we can chain this operator
    return *this;
}

int main()
{
    Fraction fiveThirds{ 5, 3 };
    Fraction f;
    f = fiveThirds; // calls overloaded assignment
    std::cout << f << '\n';

    return 0;
}
