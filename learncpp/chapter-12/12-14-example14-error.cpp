// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：auto* 要求初始化器必须是指针；若先解引用再交给 auto* 会失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// !! -error：预期编译失败，请勿修复。
//    预期错误（gcc）：unable to deduce 'auto*' from '* getPtr()'
//    （对非指针的初始化器无法推导 auto*）。
// 备注：本节代码为按原文清单忠实重建（原 Example 14）。
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
    auto ptr3{ *getPtr() };      // std::string (because we dereferenced getPtr())
    auto* ptr4{ *getPtr() };     // does not compile (initializer not a pointer)
    // --- 原文示例片段结束 ---

    return static_cast<int>(ptr3.size());
}
