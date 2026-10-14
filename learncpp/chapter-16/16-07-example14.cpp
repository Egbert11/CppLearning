// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：把长度提升到循环外单独保存，循环条件更易读（同上例，仅重排）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：9 1 2 8 3 7 6 4
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <cstddef>
#include <iostream>
#include <vector>

using Index = std::ptrdiff_t;

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    auto length{ static_cast<Index>(arr.size()) }; // hoist the length out of the loop
    for (auto index{ length - 1 }; index >= 0; --index)
        std::cout << arr[static_cast<std::size_t>(index)] << ' ';

    std::cout << '\n';

    return 0;
}
