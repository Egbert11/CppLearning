// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：C 风格数组是聚合类型，可用逗号分隔的花括号初始化列表，从元素 0
//           开始按顺序填充；拷贝列表初始化与列表初始化都可用（后者推荐）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出：2 11
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

int main()
{
    int fibonnaci[6] = { 0, 1, 1, 2, 3, 5 }; // copy-list initialization
    int prime[5] { 2, 3, 5, 7, 11 };         // list initialization (preferred)

    std::cout << fibonnaci[3] << ' ' << prime[4] << '\n';

    return 0;
}
