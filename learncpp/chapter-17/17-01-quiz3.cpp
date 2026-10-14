// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：Quiz #3 解答——用 CTAD 建一个包含 'h','e','l','l','o' 的
//           constexpr std::array，并打印下标 1 的元素。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：e
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    constexpr std::array arr { 'h', 'e', 'l', 'l', 'o' };

    std::cout << arr[1] << '\n';

    return 0;
}
