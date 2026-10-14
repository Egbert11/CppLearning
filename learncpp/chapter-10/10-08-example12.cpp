// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：auto 避免不必要的转换——getString() 返回 std::string_view；用
//           std::string 接收会做一次有代价的转换，用 auto 则不做转换。
//           （对应原文示例 14）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example12.cpp -o a
// 预期输出：
//   abc
//   abc
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

std::string_view getString()
{
    return "abc";
}

int main()
{
    // --- 原文示例片段 ---
    std::string s1{ getString() }; // 有代价的转换：string_view -> string
    auto s2{ getString() };        // 无转换，s2 是 std::string_view
    // --- 原文示例片段结束 ---

    static_assert(std::is_same_v<decltype(s1), std::string>);
    static_assert(std::is_same_v<decltype(s2), std::string_view>);

    std::cout << s1 << '\n';
    std::cout << s2 << '\n';

    return 0;
}
