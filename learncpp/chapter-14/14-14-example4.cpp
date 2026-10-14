// ============================================================
// 来源小节：14.14 Introduction to the copy constructor
// 示例说明：按值返回与按值传参——返回临时对象由拷贝构造函数初始化；再把对象
//           按值传给 printFraction 又触发一次拷贝构造。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/
// 备注：本节代码为按原文描述忠实重建。
//
// 注意：编译器可能把某些拷贝构造调用优化掉（copy elision）。在作者机器上
//       输出三次 "Copy constructor called"；你可能只看到两次。
// ============================================================
#include <iostream>

class Fraction
{
private:
    int m_numerator{ 0 };
    int m_denominator{ 1 };

public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator{ numerator }, m_denominator{ denominator }
    {
    }

    Fraction(const Fraction& fraction)
        : m_numerator{ fraction.m_numerator }
        , m_denominator{ fraction.m_denominator }
    {
        std::cout << "Copy constructor called\n";
    }

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

void printFraction(Fraction f)
{
    f.print();
}

// --- 原文示例片段（原 Example 4）---
Fraction generateFraction(int n, int d)
{
    Fraction f { n, d };
    return f;
}

int main()
{
    Fraction f2 { generateFraction(1, 2) }; // Fraction is returned by value

    printFraction(f2);

    return 0;
}
// --- 原文示例片段结束 ---

// 作者机器上的预期输出（copy elision 可能减少调用次数）：
// Copy constructor called
// Copy constructor called
// Copy constructor called
// Fraction(1, 2)
