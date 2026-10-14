// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：用字面量后缀得到想要的字符串类型——"goo"s 得 std::string，
//           "moo"sv 得 std::string_view。（对应原文示例 10）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example8.cpp -o a
// 预期输出：
//   goo
//   moo
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

using namespace std::literals;

int main()
{
    // --- 原文示例片段 ---
    auto s1{ "goo"s };  // std::string
    auto s2{ "moo"sv }; // std::string_view
    // --- 原文示例片段结束 ---

    static_assert(std::is_same_v<decltype(s1), std::string>);
    static_assert(std::is_same_v<decltype(s2), std::string_view>);

    std::cout << s1 << '\n';
    std::cout << s2 << '\n';

    return 0;
}
