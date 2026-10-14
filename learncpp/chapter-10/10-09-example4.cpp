// 来源小节：10.9 Type deduction for functions
// 示例说明：unsigned short + char 的结果类型不易一眼看出（两者都提升为 int，
//           相加得 int），用 auto 让编译器来决定返回类型。
//           （对应原文示例 4）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-functions/
//
// 编译：g++ -std=c++20 -Wall 10-09-example4.cpp -o a
// 预期输出：197（100 + 'a'(97)）
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits>

// --- 原文示例片段 ---
// let compiler determine the return type of unsigned short + char
auto add(unsigned short x, char y)
{
    return x + y;
}
// --- 原文示例片段结束 ---

int main()
{
    // unsigned short 100 提升为 int，'a'(97) 也提升为 int，相加为 int
    static_assert(std::is_same_v<decltype(add(100, 'a')), int>);
    std::cout << add(100, 'a') << '\n'; // 197（100 + 97）
    return 0;
}
