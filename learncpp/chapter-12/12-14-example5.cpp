// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：引用被丢弃后，可用 auto& 把它重新变回引用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 5）。
//       原文的 getRef() 只有原型；此处补上可编译的定义。
// ============================================================
#include <string>

std::string& getRef() // some function that returns a reference
{
    static std::string s{ "Hello" };
    return s;
}

int main()
{
    // --- 原文示例片段 ---
    auto ref1 { getRef() };  // std::string (reference dropped)
    auto& ref2 { getRef() }; // std::string& (reference dropped, reference reapplied)
    // --- 原文示例片段结束 ---

    return static_cast<int>(ref1.size() + ref2.size());
}
