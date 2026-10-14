// ============================================================
// 来源小节：14.10 Constructor member initializer lists
// 示例说明：初始化列表内难以优雅处理非法值——条件运算符能“发现问题”却“无处报告，
//           于是原文用 ??? 占位。请勿修复此文件。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
// 预期错误：g++ 报错类似 "error: expected primary-expression before '?' token"
//           （??? 不是合法表达式）。
// 备注：本节代码为按原文描述忠实重建。此文件故意编译失败，用于表达
//       “初始化列表内没有合适的错误报告途径”。
// ============================================================
// --- 原文示例片段（原 Example 8）---
class Fraction
{
private:
    int m_numerator {};
    int m_denominator {};

public:
    Fraction(int numerator, int denominator):
        m_numerator { numerator }, m_denominator { denominator != 0.0 ? denominator : ??? } // what do we do here?
    {
    }
};

int main()
{
    Fraction f{ 1, 0 };

    return 0;
}
