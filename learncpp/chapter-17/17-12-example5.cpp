// ============================================================
// 来源小节：17.12 Multidimensional C-style Arrays
// 示例说明：一维数组的两种遍历方式——带下标的 for 与范围 for（原 Example 13）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multidimensional-c-style-arrays/
// 预期输出：
//   1 2 3 4 5
//   1 2 3 4 5
// ============================================================
#include <iostream>
#include <iterator> // for std::size

int main()
{
    int arr[] { 1, 2, 3, 4, 5 };

    // 带下标的 for 循环
    for (std::size_t i { 0 }; i < std::size(arr); ++i)
        std::cout << arr[i] << ' ';
    std::cout << '\n';

    // 范围 for 循环
    for (auto e : arr)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}
