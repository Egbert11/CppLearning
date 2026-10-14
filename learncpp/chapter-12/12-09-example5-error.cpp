// ============================================================
// 来源小节：12.9 Pointers and const
// 示例说明：指向 const 值的指针可以指向非 const 变量，此时通过该指针不能
//           修改值，但通过原来的非 const 标识符仍然可以修改。与“指向 const
//           的引用”类似。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-const/
// !! -error：预期编译失败，请勿修复。
//    预期错误：assignment of read-only location '* ptr'（`*ptr = 6;` 一行）。
// 备注：本节代码为按原文清单忠实重建（原 Example 5）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 }; // non-const
    const int* ptr { &x }; // ptr points to a "const int"

    *ptr = 6;  // not allowed: ptr points to a "const int" so we can't change the value through ptr
    x = 6; // allowed: the value is still non-const when accessed through non-const identifier x
    // --- 原文示例片段结束 ---

    return 0;
}
