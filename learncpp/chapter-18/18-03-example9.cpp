// ============================================================
// 来源小节：18.3 Introduction to standard library algorithms
// 示例说明：① C++20 的 ranges 允许直接把容器传给算法（std::ranges::for_each），
//           不必再写 begin()/end()；② 算法还能跳过开头/结尾元素——用 std::next
//           跳过首元素只处理其余元素，这是范围 for 循环做不到的。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/
// 预期输出：
//   2 4 6 8
//   1 4 6 8
// 备注：本节代码为按原文描述重建；使用 C++20 ranges。
// ============================================================
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator> // for std::next

void doubleNumber(int& i)
{
    i *= 2;
}

int main()
{
    // Since C++20, ranges let us pass the container directly instead of begin()/end().
    std::array arr1{ 1, 2, 3, 4 };
    std::ranges::for_each(arr1, doubleNumber); // doubles every element
    for (int i : arr1)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // Algorithms can skip leading/trailing elements in ways a range-based for loop cannot.
    std::array arr2{ 1, 2, 3, 4 };
    std::for_each(std::next(arr2.begin()), arr2.end(), doubleNumber); // first element is not doubled
    for (int i : arr2)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
