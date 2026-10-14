// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：最简单常见的一种写法——直接用 std::size_t 作循环变量，
//           因为 size_type 几乎总是 std::size_t 的 typedef。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：4 6 7 3 8 2 1 9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    for (std::size_t index { 0 }; index < arr.size(); ++index)
        std::cout << arr[index] << ' ';

    std::cout << '\n';

    return 0;
}
