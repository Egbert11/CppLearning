// ============================================================
// 来源小节：17.2 std::array length and indexing
// 示例说明：用非成员函数 std::size()（C++17）获取长度，内部调用 size()，
//           同样返回 size_type。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/
// 预期输出：length: 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    constexpr std::array arr{ 9, 7, 5, 3, 1 };
    std::cout << "length: " << std::size(arr); // C++17, returns length as type `size_type` (alias for `std::size_t`)

    return 0;
}
