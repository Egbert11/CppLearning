// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：先丢弃引用，再丢弃（现在变成顶层的）const。初始化器是
//           const std::string& 时，推导结果是 std::string。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 9）。
//       原文的 getConstRef() 只有原型；此处补上可编译的定义。
// ============================================================
#include <string>

const std::string& getConstRef() // some function that returns a reference to const
{
    static const std::string s{ "Hello" };
    return s;
}

int main()
{
    // --- 原文示例片段 ---
    auto ref1{ getConstRef() }; // std::string (reference dropped, then top-level const dropped from result)
    // --- 原文示例片段结束 ---

    return static_cast<int>(ref1.size());
}
