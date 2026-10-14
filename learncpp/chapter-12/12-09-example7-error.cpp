// ============================================================
// 来源小节：12.9 Pointers and const
// 示例说明：const 指针必须初始化，且初始化后不能再指向别的地址。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-const/
// !! -error：预期编译失败，请勿修复。
//    预期错误：assignment of read-only variable 'ptr'（对只读变量 ptr 赋值）。
// 备注：本节代码为按原文清单忠实重建（原 Example 7）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 };
    int y{ 6 };

    int* const ptr { &x }; // okay: the const pointer is initialized to the address of x
    ptr = &y; // error: once initialized, a const pointer can not be changed.
    // --- 原文示例片段结束 ---

    return 0;
}
