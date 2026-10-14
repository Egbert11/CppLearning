// ============================================================
// 来源小节：12.9 Pointers and const
// 示例说明：const 指针——把 const 写在星号右边，表示“指针的地址在初始化后
//           不能再改变”。与任何 const 变量一样，它必须在定义时初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointers-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 6）。
// ============================================================

int main()
{
    // --- 原文示例片段 ---
    int x{ 5 };
    int* const ptr { &x }; // const after the asterisk means this is a const pointer
    // --- 原文示例片段结束 ---

    // 下面这行不是原文内容，仅用于让编译器不报告“变量未使用”。
    return *ptr;
}
