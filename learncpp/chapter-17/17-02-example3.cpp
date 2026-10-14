// ============================================================
// 来源小节：17.2 std::array length and indexing
// 示例说明：std::ssize()（C++20）返回"大的有符号类型"（通常是 std::ptrdiff_t）
//           表示的长度——它是唯一返回有符号值的方案。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/
// 预期输出：length: 5
// 备注：本节代码为按原文描述重建，需 -std=c++20。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    constexpr std::array arr { 9, 7, 5, 3, 1 };
    std::cout << "length: " << std::ssize(arr); // C++20, returns length as a large signed integral type

    return 0;
}
