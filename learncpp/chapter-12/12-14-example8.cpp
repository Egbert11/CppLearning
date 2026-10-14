// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：一个指针可以同时带有两种 const：左侧的 const 是底层 const，
//           右侧的 const 是顶层 const。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：原文片段无初始化；此处补上目标对象以便编译（原 Example 8）。
// ============================================================
//
// 原文示例片段：
//   const int* const ptr; // the left const is low-level, the right const is top-level

int main()
{
    // --- 原文示例片段（补初始化以便编译）---
    int value { 5 };
    const int* const ptr { &value }; // the left const is low-level, the right const is top-level
    // --- 原文示例片段结束 ---

    return *ptr;
}
