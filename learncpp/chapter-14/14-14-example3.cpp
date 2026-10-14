// ============================================================
// 来源小节：14.14 Introduction to the copy constructor
// 示例说明：按值传参时，实参被拷贝进形参；当实参与形参类型相同，拷贝通过
//           隐式调用拷贝构造函数完成。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/
// 备注：本节代码为按原文描述忠实重建。
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

// --- 原文示例片段（原 Example 3）---
void printFraction(Fraction f) // f is passed by value
{
    f.print();
}

int main()
{
    Fraction f { 5, 3 };

    printFraction(f); // f is copied into the parameter by the copy constructor

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// Copy constructor called
// Fraction(5, 3)
