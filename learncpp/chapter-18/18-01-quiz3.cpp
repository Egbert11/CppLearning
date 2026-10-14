// ============================================================
// 来源小节：18.1 Sorting an array using selection sort
// 示例说明：Quiz #3 解答——未优化的冒泡排序（bubble sort）。反复比较相邻
//           的一对元素，若前一个更大就交换，使较大元素逐步“冒泡”到末尾。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort/
// 预期输出：1 2 3 4 5 6 7 8 9
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm> // for std::swap
#include <array>
#include <iostream>

int main()
{
    std::array<int, 9> array{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };

    for (std::size_t iteration{ 0 }; iteration < array.size() - 1; ++iteration)
    {
        for (std::size_t currentIndex{ 0 }; currentIndex < array.size() - 1; ++currentIndex)
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
            }
        }
    }

    for (int i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
