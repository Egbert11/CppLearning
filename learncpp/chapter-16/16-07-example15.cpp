// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：C++20 的 std::ssize() 直接返回有符号长度，倒序循环无需手写长度转换；
//           下标访问时仍要转回 std::size_t。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：9 1 2 8 3 7 6 4
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    for (auto index{ std::ssize(arr) - 1 }; index >= 0; --index) // std::ssize introduced in C++20
        std::cout << arr[static_cast<std::size_t>(index)] << ' ';

    std::cout << '\n';

    return 0;
}
