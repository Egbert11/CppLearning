// ============================================================
// 来源小节：12.9 Pointers and const
// 示例说明：指向 const 值的 const 指针——星号左右各有一个 const，地址和
//           被指向的值都不能改，只能解引用读取。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 9）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    int value { 5 };
    const int* const ptr { &value }; // a const pointer to a const value
    // --- 原文示例片段结束 ---

    // 下面这行不是原文内容，仅用于让编译器不报告“变量未使用”。
    return *ptr;
}
