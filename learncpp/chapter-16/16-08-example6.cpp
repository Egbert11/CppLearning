// ============================================================
// 来源小节：16.8 Range-based for loops (for-each)
// 示例说明：范围 for 循环不仅适用于 std::vector，也能直接遍历 std::array。
// 原文链接：https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/
// 预期输出：0 1 1 2 3 5 8 13 21 34 55 89
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    std::array fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    for (auto number : fibonacci)
        std::cout << number << ' ';

    std::cout << '\n';

    return 0;
}
