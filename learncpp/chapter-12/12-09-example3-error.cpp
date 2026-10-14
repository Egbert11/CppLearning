// ============================================================
// 来源小节：12.9 Pointers and const
// 示例说明：指向 const 值的指针（pointer to const value）——指针本身不是
//           const，但被指向的类型是 const，因此不能通过它修改值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-const/
// !! -error：预期编译失败，请勿修复。
//    预期错误：assignment of read-only location '* ptr'（对只读位置赋值）。
// 备注：本节代码为按原文清单忠实重建（原 Example 3）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    const int x{ 5 };
    const int* ptr { &x }; // okay: ptr is pointing to a "const int"

    *ptr = 6; // not allowed: we can't change a const value
    // --- 原文示例片段结束 ---

    return 0;
}
