// ============================================================
// 来源小节：17.9 Pointer arithmetic and subscripting
// 示例说明：范围 for 循环遍历数组（原 Example 10）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
// 预期输出：9 7 5 3 1
// ============================================================
#include <iostream>

int main()
{
    constexpr int arr[]{ 9, 7, 5, 3, 1 };

    for (auto e : arr)
    {
        std::cout << e << ' ';
    }

    return 0;
}
