// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：底层 const（low-level const）——作用在通过引用或指针访问的对象
//           上的 const。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：原文片段若不加初始化不能编译；此处补上目标对象，语义不变（原 Example 7）。
// ============================================================
//
// 原文示例片段：
//   const int& ref; // this const applies to the object being referenced, so it is low-level
//   const int* ptr; // this const applies to the object being pointed to, so it is low-level

int main()
{
    // --- 原文示例片段（补初始化以便编译）---
    int value { 5 };
    const int& ref { value };  // this const applies to the object being referenced, so it is low-level
    const int* ptr { &value }; // this const applies to the object being pointed to, so it is low-level
    // --- 原文示例片段结束 ---

    return ref + *ptr;
}
