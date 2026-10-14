// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：对 const 引用初始化器，重新施加引用和/或 const 的各种组合。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 10）。
//       原文的 getConstRef() 只有原型；此处补上可编译的定义。
// ============================================================
#include <string>

const std::string& getConstRef() // some function that returns a const reference
{
    static const std::string s{ "Hello" };
    return s;
}

int main()
{
    // --- 原文示例片段 ---
    auto ref1{ getConstRef() };        // std::string (reference and top-level const dropped)
    const auto ref2{ getConstRef() };  // const std::string (reference dropped, const dropped, const reapplied)

    auto& ref3{ getConstRef() };       // const std::string& (reference dropped and reapplied, low-level const not dropped)
    const auto& ref4{ getConstRef() }; // const std::string& (reference dropped and reapplied, low-level const not dropped)
    // --- 原文示例片段结束 ---

    return static_cast<int>(ref1.size() + ref2.size() + ref3.size() + ref4.size());
}
