// ============================================================
// 来源小节：14.14 Introduction to the copy constructor
// 示例说明：用 = default 显式请求编译器生成默认拷贝构造函数，行为同隐式版本。
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

    // --- 原文示例片段（原 Example 5）---
    Fraction(const Fraction& fraction) = default; // explicitly request default copy constructor
    // --- 原文示例片段结束 ---

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };
    Fraction fCopy { f };

    f.print();
    fCopy.print();

    return 0;
}

// 预期输出：
// Fraction(5, 3)
// Fraction(5, 3)
