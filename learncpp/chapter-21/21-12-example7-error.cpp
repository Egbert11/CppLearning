// 来源小节：21.12 Overloading the assignment operator
// 示例说明：用 = delete 把拷贝构造函数和拷贝赋值运算符都删掉，从而禁止该类的拷贝与赋值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/
// 说明：本节代码为按原文描述重建。此文件预期编译失败（勿修复！）：
//       error: use of deleted function 'Fraction& Fraction::operator=(const Fraction&)'
//       （此外分数 f = fiveThirds 还会因拷贝被删而报 use of deleted function）

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

    Fraction(const Fraction& copy) = delete;            // no copies
    Fraction& operator= (const Fraction& fraction) = delete; // no copies through assignment!

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

int main()
{
    Fraction fiveThirds{ 5, 3 };
    Fraction f;
    f = fiveThirds; // compile error, operator= has been deleted
    std::cout << f << '\n';

    return 0;
}
