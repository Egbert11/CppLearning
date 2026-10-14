// ============================================================
// 来源小节：14.14 Introduction to the copy constructor
// 示例说明：隐式拷贝构造函数——未定义拷贝构造函数时，编译器生成一个
//           执行逐成员初始化的公开隐式拷贝构造函数，Fraction fCopy { f }; 触发它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 1）---
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

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };   // Calls Fraction(int, int) constructor
    Fraction fCopy { f };  // Calls (implicit) copy constructor

    f.print();
    fCopy.print();

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// Fraction(5, 3)
// Fraction(5, 3)
