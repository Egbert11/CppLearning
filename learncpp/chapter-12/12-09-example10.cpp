// ============================================================
// 来源小节：12.9 Pointers and const
// 示例说明：并列给出四种“指针 + const”组合，说明 const 落在星号左边还是
//           右边决定了它约束的是“值”还是“指针”。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 10）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    int v{ 5 };

    int* ptr0 { &v };             // points to an "int" but is not const itself.  We can modify the value or the address.
    const int* ptr1 { &v };       // points to a "const int" but is not const itself.  We can only modify the address.
    int* const ptr2 { &v };       // points to an "int" and is const itself.   We can only modify the value.
    const int* const ptr3 { &v }; // points to a "const int" and is const itself.  We can't modify the value nor the address.

    // if the const is on the left side of the *, the const belongs to the value
    // if the const is on the right side of the *, the const belongs to the pointer
    // --- 原文示例片段结束 ---

    // 下面这几行不是原文内容，仅用于让编译器不报告“变量未使用”。
    return *ptr0 + *ptr1 + *ptr2 + *ptr3;
}
