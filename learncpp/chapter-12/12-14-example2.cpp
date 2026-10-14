// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：默认的 auto 推导会**丢弃 const**（以及 constexpr 隐含的 const）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 2）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    const double a { 7.8 }; // a has type const double
    auto b { a };           // b has type double (const dropped)

    constexpr double c { 7.8 }; // c has type const double (constexpr implicitly applies const)
    auto d { c };               // d has type double (const dropped)
    // --- 原文示例片段结束 ---

    return static_cast<int>(b + d);
}
