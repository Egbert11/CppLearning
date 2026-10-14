// ============================================================
// 来源小节：16.8 Range-based for loops (for-each)
// 示例说明：用范围 for 循环遍历同一个斐波那契 vector——不需要长度，也不需要下标；
//           第二段演示用 auto 让编译器推导元素类型（int）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/
// 预期输出：
//   0 1 1 2 3 5 8 13 21 34 55 89
//   0 1 1 2 3 5 8 13 21 34 55 89
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

    // 范围 for 循环：num 是元素的一个副本，不是下标
    for (int num : fibonacci)
        std::cout << num << ' ';
    std::cout << '\n';

    // 用类型推导：让编译器把 num 推导为 int，避免重复书写、也避免写错
    for (auto num : fibonacci)
        std::cout << num << ' ';
    std::cout << '\n';

    return 0;
}
