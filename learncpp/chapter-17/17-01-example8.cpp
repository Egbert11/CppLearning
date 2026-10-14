// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：const std::array 的元素也被当作 const 对待；constexpr std::array
//           可在常量表达式中使用（这正是使用 std::array 的关键理由）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：11 25
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    const std::array<int, 5> prime { 2, 3, 5, 7, 11 };          // elements are treated as const
    constexpr std::array<int, 5> squares { 1, 4, 9, 16, 25 };   // fully constexpr

    static_assert(squares[4] == 25); // usable in constant expressions

    std::cout << prime[4] << ' ' << squares[4] << '\n';

    return 0;
}
