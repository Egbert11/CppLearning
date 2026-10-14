// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：用字面量下标和 constexpr 下标索引都可以，隐式转换为 std::size_t 且不算收窄。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：7
//           7
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    std::cout << prime[3] << '\n';     // okay: 3 converted from int to std::size_t, not a narrowing conversion

    constexpr int index { 3 };         // constexpr
    std::cout << prime[index] << '\n'; // okay: constexpr index implicitly converted to std::size_t, not a narrowing conversion

    return 0;
}
