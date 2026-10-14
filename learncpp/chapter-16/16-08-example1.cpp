// ============================================================
// 来源小节：16.8 Range-based for loops (for-each)
// 示例说明：基于下标的普通 for 循环遍历 std::vector，这是范围 for 循环要替代的写法。
//           这种写法灵活但容易差一，也容易遇到下标符号问题。
// 原文链接：https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/
// 预期输出：0 1 1 2 3 5 8 13 21 34 55 89
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    // 这 12 个数是斐波那契数列的前 12 项
    std::vector fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    // Before C++17 (no CTAD), you would write:
    // std::vector<int> fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    for (std::size_t index { 0 }; index < fibonacci.size(); ++index)
        std::cout << fibonacci[index] << ' ';

    std::cout << '\n';

    return 0;
}
