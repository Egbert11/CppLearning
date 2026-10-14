// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：用 C++17 的非成员函数 std::size() 取长度（对容器就是调用成员 size()）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：length: 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector prime { 2, 3, 5, 7, 11 };
    std::cout << "length: " << std::size(prime); // C++17, returns length as type `size_type` (alias for `std::size_t`)

    return 0;
}
