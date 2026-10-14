// ============================================================
// 来源小节：14.14 Introduction to the copy constructor
// 示例说明：自定义拷贝构造函数——参数为 const 左值引用；可逐成员复制并打印
//           提示。注意访问控制按类而非按对象生效，故可访问 fraction 的私有成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-copy-constructor/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 2）---
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

    Fraction(const Fraction& fraction) // copy constructor
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

int main()
{
    Fraction f { 5, 3 };
    Fraction fCopy { f };

    f.print();
    fCopy.print();

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// Copy constructor called
// Fraction(5, 3)
// Fraction(5, 3)
