// ============================================================
// 来源小节：12.9 Pointers and const
// 示例说明：const 指针指向的值（非 const）仍可通过该指针修改。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 8）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 };
    int* const ptr { &x }; // ptr will always point to x

    *ptr = 6; // okay: the value being pointed to is non-const
    // --- 原文示例片段结束 ---

    // 下面这行不是原文内容，仅用于让编译器不报告“变量未使用”。
    return *ptr;
}
