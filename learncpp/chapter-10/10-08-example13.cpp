// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：auto 的坏处——不小心用 int 字面量得到一个 int（本意可能是 double），
//           以及隐藏的整数除法（本意可能是浮点除法，结果却是 1）。
//           （对应原文示例 15、16）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example13.cpp -o a
// 预期输出：
//   1
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits>

int main()
{
    // --- 原文示例片段（示例 15：本意 double 却写成 int 字面量） ---
    auto y{ 5 }; // y 是 int；若写成 5.0 则 y 会是 double
    // --- 原文示例片段结束 ---
    static_assert(std::is_same_v<decltype(y), int>);

    // --- 原文示例片段（示例 16：隐藏的整数除法） ---
    auto x{ 3 };
    auto z{ 2 };
    std::cout << x / z << '\n'; // oops：本意可能是浮点除法，实际是整数除法 1
    // --- 原文示例片段结束 ---

    return 0;
}
