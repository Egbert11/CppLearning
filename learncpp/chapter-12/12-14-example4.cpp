// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：初始化器是引用时，推导会**丢弃引用**，得到被引用对象的类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 4）。
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
    auto ref { getRef() }; // type deduced as std::string (not std::string&)
    // --- 原文示例片段结束 ---

    return static_cast<int>(ref.size());
}
