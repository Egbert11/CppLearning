// ============================================================
// 来源小节：12.9 Pointers and const
// 示例说明：普通（非 const）指针既能重新指向别的对象，也能通过解引用修改
//           被指向的值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 1）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int* ptr { &x }; // ptr is a normal (non-const) pointer

    int y { 6 };
    ptr = &y; // we can point at another value

    *ptr = 7; // we can change the value at the address being held
    // --- 原文示例片段结束 ---

    // 下面这行不是原文内容，仅用于让编译器不报告“变量未使用”。
    return y;
}
