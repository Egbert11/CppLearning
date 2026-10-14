// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：C++20 之前获得有符号长度的办法——static_cast 转 size() 的结果，
//           再做倒序循环。
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

    for (auto index{ static_cast<Index>(arr.size()) - 1 }; index >= 0; --index)
        std::cout << arr[static_cast<std::size_t>(index)] << ' ';

    std::cout << '\n';

    return 0;
}
