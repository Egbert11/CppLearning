// ============================================================
// 来源小节：16.5 Returning std::vector, and an introduction to move semantics
// 示例说明：拷贝语义——arr2 由 arr1 拷贝构造而来，是独立副本，
//           因此分别修改 arr1[0]、arr2[0] 互不影响。
// 原文链接：https://www.learncpp.com/cpp-tutorial/returning-stdvector-and-an-introduction-to-move-semantics/
// 预期输出：67
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector arr1 { 1, 2, 3, 4, 5 }; // copies { 1, 2, 3, 4, 5 } into arr1
    std::vector arr2 { arr1 };          // copies arr1 into arr2

    arr1[0] = 6; // We can continue to use arr1
    arr2[0] = 7; // and we can continue to use arr2

    std::cout << arr1[0] << arr2[0] << '\n';

    return 0;
}
