// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：std::array 是聚合类型，用聚合初始化按顺序填充元素；拷贝列表
//           初始化与列表初始化都可用（后者更受推荐）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期输出：2 11
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <array>
#include <iostream>

int main()
{
    std::array<int, 6> fibonnaci = { 0, 1, 1, 2, 3, 5 }; // copy-list initialization
    std::array<int, 5> prime { 2, 3, 5, 7, 11 };         // list initialization (preferred)

    std::cout << fibonnaci[3] << ' ' << prime[4] << '\n';

    return 0;
}
