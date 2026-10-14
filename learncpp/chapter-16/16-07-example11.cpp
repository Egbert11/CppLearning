// ============================================================
// 来源小节：16.7 Arrays, loops, and sign challenge solutions
// 示例说明：用 auto 从初始化器推导索引类型——起始下标来自
//           static_cast<std::ptrdiff_t>(arr.size())-1，倒序遍历。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/
// 预期输出：9 1 2 8 3 7 6 4
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <cstddef>
#include <iostream>
#include <vector>

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    for (auto index{ static_cast<std::ptrdiff_t>(arr.size()) - 1 }; index >= 0; --index)
        std::cout << arr[static_cast<std::size_t>(index)] << ' ';

    std::cout << '\n';

    return 0;
}
