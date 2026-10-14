// ============================================================
// 来源小节：17.2 std::array length and indexing
// 示例说明：三个长度函数都返回 constexpr 值，即使数组对象本身不是 constexpr
//           也能用于常量表达式；std::size_t 到 int 的隐式转换不算窄化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/
// 预期输出：length: 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    std::array arr { 9, 7, 5, 3, 1 }; // note: not constexpr for this example
    constexpr int length{ std::size(arr) }; // ok: return value is constexpr std::size_t and can be converted to int, not a narrowing conversion

    std::cout << "length: " << length << '\n';

    return 0;
}
