// ============================================================
// 来源小节：12.9 Pointers and const
// 示例说明：指向 const 值的指针本身不是 const，因此可以重新指向另一个
//           const 对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 4）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    const int x{ 5 };
    const int* ptr { &x }; // ptr points to const int x

    const int y{ 6 };
    ptr = &y; // okay: ptr now points at const int y
    // --- 原文示例片段结束 ---

    // 下面这行不是原文内容，仅用于让编译器不报告“变量未使用”。
    return *ptr;
}
