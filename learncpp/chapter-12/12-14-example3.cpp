// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：在推导出的类型上重新施加 const 或 constexpr。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 3）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    double a { 7.8 };    // a has type double
    const auto b { a };  // b has type const double (const applied)

    constexpr double c { 7.8 }; // c has type const double (constexpr implicitly applies const)
    const auto d { c };         // d is const double (const dropped, const reapplied)
    constexpr auto e { c };     // e is constexpr double (const dropped, constexpr reapplied)
    // --- 原文示例片段结束 ---

    return static_cast<int>(b + d + e);
}
