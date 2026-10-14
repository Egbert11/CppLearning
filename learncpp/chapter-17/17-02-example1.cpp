// ============================================================
// 来源小节：17.2 std::array length and indexing
// 示例说明：用成员函数 size() 获取 std::array 的长度，返回类型为 size_type
//           （即 std::size_t 的别名）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdarray-length-and-indexing/
// 预期输出：length: 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    constexpr std::array arr { 9.0, 7.2, 5.4, 3.6, 1.8 };
    std::cout << "length: " << arr.size() << '\n'; // returns length as type `size_type` (alias for `std::size_t`)

    return 0;
}
