// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：推导丢弃顶层 const；想要 const 就自己加回 const auto。
//           （对应原文示例 7、8）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example6.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits>

int main()
{
    const int a{ 5 };

    // --- 原文示例片段（示例 7：const 被丢弃） ---
    auto b{ a }; // b 是 int（const 被丢弃）
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（示例 8：手动加回 const） ---
    const auto c{ a }; // c 是 const int
    // --- 原文示例片段结束 ---

    static_assert(std::is_same_v<decltype(b), int>);
    static_assert(std::is_same_v<decltype(c), const int>);

    std::cout << b << ' ' << c << '\n';

    return 0;
}
