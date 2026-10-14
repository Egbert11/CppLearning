// ============================================================
// 来源小节：12.3 Lvalue references
// 示例说明：用另一个引用初始化一个引用，并不会产生"引用的引用"；
//           ref2 仍只是绑定到最初对象 var 的普通左值引用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references/
// 备注：本节代码为按原文描述忠实重建（原 Example 10）。
//       真正的"引用的引用"语法是 int&&，但 C++ 不支持它，
//       该语法在 C++11 被改用作右值引用。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    int var{};
    int& ref1{ var };  // an lvalue reference bound to var
    int& ref2{ ref1 }; // an lvalue reference bound to var (not a reference to a reference)
    // --- 原文示例片段结束 ---

    (void)ref2;

    return 0;
}
