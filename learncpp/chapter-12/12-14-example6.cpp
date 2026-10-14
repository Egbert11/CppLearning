// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：顶层 const（top-level const）——作用在对象自身的 const，例如
//           变量上、或指针变量上的 const。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：原文片段为无初始化声明，不能直接编译；此处补上初始化与目标对象，
//       语义不变（原 Example 6）。
// ============================================================
//
// 原文示例片段（无初始化，单独不能编译）：
//   const int x;    // this const applies to x, so it is top-level
//   int* const ptr; // this const applies to ptr, so it is top-level
//   // references don't have a top-level const syntax, as they are implicitly top-level const

int main()
{
    // --- 原文示例片段（补初始化以便编译）---
    const int x { 5 };         // this const applies to x, so it is top-level
    int value { 5 };
    int* const ptr { &value }; // this const applies to ptr, so it is top-level
    // references don't have a top-level const syntax, as they are implicitly top-level const
    // --- 原文示例片段结束 ---

    return x + *ptr;
}
