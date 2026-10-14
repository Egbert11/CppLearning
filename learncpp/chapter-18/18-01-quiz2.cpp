// ============================================================
// 来源小节：18.1 Sorting an array using selection sort
// 示例说明：Quiz #2 解答——把选择排序改成“从大到小”。只需把内层比较
//           由 `<` 改为 `>`，并把 smallestIndex 改名为 largestIndex。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort/
// 预期输出：50 40 30 20 10
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm> // for std::swap
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> array{ 30, 50, 20, 10, 40 };

    for (std::size_t startIndex{ 0 }; startIndex < array.size() - 1; ++startIndex)
    {
        std::size_t largestIndex{ startIndex };

        for (std::size_t currentIndex{ startIndex + 1 }; currentIndex < array.size(); ++currentIndex)
        {
            if (array[currentIndex] > array[largestIndex])
            {
                largestIndex = currentIndex;
            }
        }

        std::swap(array[startIndex], array[largestIndex]);
    }

    for (int i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
