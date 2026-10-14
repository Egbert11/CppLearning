// ============================================================
// 来源小节：22.5 std::unique_ptr
// 示例说明：用 std::make_unique 创建单个 Fraction（3/5）与长度为 4 的
//           Fraction 数组（默认构造 0/1）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   3/5
//   0/1
// 备注：本节代码为按原文描述重建（原 Example 5）。
// ============================================================
#include <iostream>
#include <memory> // for std::unique_ptr and std::make_unique

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
    // Create a single dynamically allocated Fraction with numerator 3 and denominator 5
    // We can also use automatic type deduction to good effect here
    auto f1{ std::make_unique<Fraction>(3, 5) };
    std::cout << *f1 << '\n';

    // Create a dynamically allocated array of Fractions of length 4
    auto f2{ std::make_unique<Fraction[]>(4) };
    std::cout << f2[0] << '\n';

    return 0;
}
