// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：字面量后缀决定推导出的类型——1.23f 得 float，5u 得 unsigned int。
//           （对应原文示例 4）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example4.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>
#include <type_traits>

int main()
{
    // --- 原文示例片段 ---
    auto a{ 1.23f }; // f 后缀 -> float
    auto b{ 5u };    // u 后缀 -> unsigned int
    // --- 原文示例片段结束 ---

    static_assert(std::is_same_v<decltype(a), float>);
    static_assert(std::is_same_v<decltype(b), unsigned int>);

    std::cout << a << ' ' << b << '\n';

    return 0;
}
