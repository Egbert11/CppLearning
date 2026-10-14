// ============================================================
// 来源小节：12.4 Lvalue references to const
// 示例说明：const 左值引用可以绑定 const 左值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
// 备注：本节代码为按原文描述忠实重建（原 Example 2）。
// ============================================================
int main()
{
    // --- 原文示例片段 ---
    const int x { 5 };    // x is a non-modifiable lvalue
    const int& ref { x }; // okay: ref is an lvalue reference to a const value
    // --- 原文示例片段结束 ---

    (void)ref;

    return 0;
}
