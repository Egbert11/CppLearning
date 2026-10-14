// ============================================================
// 来源小节：14.14 Introduction to the copy constructor
// 示例说明：用 = delete 把拷贝构造函数标记为删除，从而禁止拷贝；
//           任何拷贝尝试都会导致编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/
// 备注：本节代码为按原文描述忠实重建。
//
// *** 本文件为预期编译失败示例（-error），请勿"修复" ***
// 预期错误：Fraction fCopy { f }; 处——调用被删除的拷贝构造函数
//           （use of deleted function 'Fraction::Fraction(const Fraction&)'）。
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

    // --- 原文示例片段（原 Example 6）---
    Fraction(const Fraction& fraction) = delete; // disallow copying
    // --- 原文示例片段结束 ---

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };
    Fraction fCopy { f }; // compile error: copy constructor is deleted

    f.print();
    fCopy.print();

    return 0;
}
