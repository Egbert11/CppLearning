// ============================================================
// 来源小节：18.1 Sorting an array using selection sort
// 示例说明：Quiz #4 解答——优化后的冒泡排序：① 每轮不再重排已经就位的
//           末尾元素（endOfArrayIndex）；② 若某一轮完全没有发生交换，
//           说明已排好，提前终止并打印终止时的轮次。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort/
// 预期输出：
//   Early termination on iteration 6
//   1 2 3 4 5 6 7 8 9
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
        // keep track of whether or not we swapped this iteration
        bool swapped{ false };

        // the last `iteration` elements are already sorted, so don't check them
        std::size_t endOfArrayIndex{ array.size() - iteration };

        for (std::size_t currentIndex{ 0 }; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swapped = true;
            }
        }

        // If we didn't swap any elements, then the array is already sorted
        if (!swapped)
        {
            std::cout << "Early termination on iteration " << iteration + 1 << '\n';
            break;
        }
    }

    for (int i : array)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
