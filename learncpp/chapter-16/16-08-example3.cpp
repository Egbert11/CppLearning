// ============================================================
// 来源小节：16.8 Range-based for loops (for-each)
// 示例说明：对空的 std::vector 做范围 for 循环——由于没有元素，
//           循环体一次都不会执行，因此什么都不打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/
// 预期输出：（无输出）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> empty {}; // 空容器

    for ([[maybe_unused]] auto element : empty)
        std::cout << "Hi mom!\n"; // 永远不会执行

    return 0;
}
