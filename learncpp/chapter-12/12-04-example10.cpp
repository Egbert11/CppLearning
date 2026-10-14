// ============================================================
// 来源小节：12.4 Lvalue references to const
// 示例说明：constexpr 引用若指向 const 变量，需要同时写 constexpr 和
//           const。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
// 备注：本节代码为按原文描述忠实重建（原 Example 10）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    static const int s_x { 6 }; // a const int
    [[maybe_unused]] constexpr const int& ref2 { s_x }; // needs both constexpr and const
    // --- 原文示例片段结束 ---

    return 0;
}
