// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：下标变量为 std::size_t 时，operator[] 无需任何转换，无警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期输出：7
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    std::size_t index { 3 };           // non-constexpr, but already the right type
    std::cout << prime[index] << '\n'; // operator[] expects an index of type std::size_t, no conversion required

    return 0;
}
