// ============================================================
// 来源小节：22.5 std::unique_ptr（本节测验·原始版本）
// 示例说明：测验的起点程序——用裸指针 new 一个 Fraction，打印后再手动
//           delete。测验要求把它改成使用 std::unique_ptr。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// 预期输出：
//   3/5
// 备注：本节代码为按原文描述重建（原 Example 12）。解答见 22-05-quiz1.cpp。
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

void printFraction(const Fraction* ptr)
{
    if (ptr)
        std::cout << *ptr << '\n';
    else
        std::cout << "No fraction\n";
}

int main()
{
    auto* ptr{ new Fraction{ 3, 5 } };

    printFraction(ptr);

    delete ptr;

    return 0;
}
