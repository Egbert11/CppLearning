// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：用成员函数 size() 取 vector 长度，返回类型为 size_type（即 std::size_t 别名）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：length: 5
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector prime { 2, 3, 5, 7, 11 };
    std::cout << "length: " << prime.size() << '\n'; // returns length as type `size_type` (alias for `std::size_t`)
    return 0;
}
