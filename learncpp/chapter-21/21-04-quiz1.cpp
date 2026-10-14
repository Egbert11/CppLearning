// 来源小节：21.4 Overloading the I/O operators（Quiz Question #1 解答）
// 示例说明：为 Fraction 增加 operator<< 和 operator>>。operator>> 是事务式的：
//           先读到局部变量；分母为 0 时手动置 failbit；只有整个人不在失败态时
//           才把对象更新为抽取值（失败时保持原对象，不重置为默认值）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
// 说明：本节代码取自原文（逐字保留）。需要从 stdin 读入两个分数，例如输入
//       2/3 与 3/8。
// 预期输出（对应输入 2/3 与 3/8）：
//   Enter fraction 1: 2/3
//   Enter fraction 2: 3/8
//   2/3 * 3/8 is 1/4

#include <iostream>
#include <limits>
#include <numeric> // for std::gcd

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction(int numerator=0, int denominator = 1) :
        m_numerator{ numerator }, m_denominator{ denominator }
    {
        // We put reduce() in the constructor to ensure any new fractions we make get reduced!
        // Any fractions that are overwritten will need to be re-reduced
        reduce();
    }

    void reduce()
    {
        int gcd{ std::gcd(m_numerator, m_denominator) };
        if (gcd)
        {
            m_numerator /= gcd;
            m_denominator /= gcd;
        }
    }

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int value);
    friend Fraction operator*(int value, const Fraction& f1);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

    void print() const
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction { f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

Fraction operator*(const Fraction& f1, int value)
{
    return Fraction { f1.m_numerator * value, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1)
{
    return Fraction { f1.m_numerator * value, f1.m_denominator };
}

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
    out << f1.m_numerator << '/' << f1.m_denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f1)
{
    int numerator {};
    char ignore {};
    int denominator {};

    in >> numerator >> ignore >> denominator;
    if (denominator == 0)                       // if our denominator is semantically invalid
        in.setstate(std::ios_base::failbit);    // set failure mode manually
    if (in)                                     // if we're not in failure mode
        f1 = Fraction {numerator, denominator}; // update our object to the extracted values

    return in;
}

int main()
{
    Fraction f1{};
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2{};
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}
