// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：auto / auto* 与 const 的位置组合。const 在左作用于被指对象，
//           在右作用于指针本身。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 15）。
//       原文的 getPtr() 只有原型；此处补上可编译的定义。
// ============================================================
#include <string>

std::string* getPtr() // some function that returns a pointer
{
    static std::string s{ "Hello" };
    return &s;
}

int main()
{
    // --- 原文示例片段 ---
    const auto ptr1{ getPtr() };  // std::string* const
    auto const ptr2 { getPtr() }; // std::string* const

    const auto* ptr3{ getPtr() }; // const std::string*
    auto* const ptr4{ getPtr() }; // std::string* const
    // --- 原文示例片段结束 ---

    return static_cast<int>(ptr1->size() + ptr2->size() + ptr3->size() + ptr4->size());
}
