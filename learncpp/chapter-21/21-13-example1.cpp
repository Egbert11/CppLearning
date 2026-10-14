// 来源小节：21.13 Shallow vs. deep copying
// 示例说明：Fraction 只含简单的非动态成员，编译器生成的拷贝构造函数 / 拷贝赋值运算符
//           做“逐成员复制（浅拷贝）”即可，完全正确，无需自己手写。
// 原文链接：https://www.learncpp.com/cpp-tutorial/shallow-vs-deep-copying/
// 说明：本节代码为按原文描述重建。
// 预期输出：3/5

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
        // We put a assert here to enforce that denominator must not be 0
        assert(denominator != 0);
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

int main()
{
    Fraction f{ 3, 5 };
    Fraction copy{ f }; // uses compiler-generated copy constructor (memberwise/shallow copy) - fine here

    std::cout << copy << '\n'; // prints 3/5

    return 0;
}
