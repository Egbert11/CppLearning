// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：auto 与 auto* 在推导指针时的对比。auto 时指针属于被推导的类型；
//           auto* 时推导的是被指类型，指针在之后重新施加。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 13）。
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
    auto ptr1{ getPtr() };  // std::string*
    auto* ptr2{ getPtr() }; // std::string*
    // --- 原文示例片段结束 ---

    return static_cast<int>(ptr1->size() + ptr2->size());
}
