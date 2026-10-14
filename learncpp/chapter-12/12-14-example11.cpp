// ============================================================
// 来源小节：12.14 Type deduction with pointers, references, and const
// 示例说明：constexpr 引用指向 const 对象（配合 std::string_view）。
//           constexpr 不属于表达式的类型，auto 永远不会推导出它，必须显式施加。
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-with-pointers-references-and-const/
// 备注：本节代码为按原文清单忠实重建（原 Example 11）。
// ============================================================
#include <iostream>
#include <string_view>

constexpr std::string_view hello { "Hello" };   // implicitly const

constexpr const std::string_view& getConstRef() // function is constexpr, returns a const std::string_view&
{
    return hello;
}

int main()
{
    // --- 原文示例片段 ---
    auto ref1{ getConstRef() };                  // std::string_view (reference dropped and top-level const dropped)
    constexpr auto ref2{ getConstRef() };        // constexpr const std::string_view (reference dropped and top-level const dropped, constexpr applied, implicitly const)

    auto& ref3{ getConstRef() };                 // const std::string_view& (reference reapplied, low-level const not dropped)
    constexpr const auto& ref4{ getConstRef() }; // constexpr const std::string_view& (reference reapplied, low-level const not dropped, constexpr applied)
    // --- 原文示例片段结束 ---

    std::cout << ref1 << ref2 << ref3 << ref4 << '\n';

    return 0;
}
