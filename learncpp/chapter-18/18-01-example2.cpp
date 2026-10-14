// ============================================================
// 来源小节：18.1 Sorting an array using selection sort
// 示例说明：选择排序（selection sort）的完整实现。外层循环选出 startIndex，
//           内层循环在剩余元素中找出最小值的下标 smallestIndex，然后交换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sorting-an-array-using-selection-sort/
// 预期输出：10 20 30 40 50
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <algorithm> // for std::swap
#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> array{ 30, 50, 20, 10, 40 };

    // Step through each element of the array
    // (except the last one, which will already be sorted by the time we get there)
    for (std::size_t startIndex{ 0 }; startIndex < array.size() - 1; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        std::size_t smallestIndex{ startIndex };

        // Look for smallest element remaining in the array (starting at startIndex+1)
        for (std::size_t currentIndex{ startIndex + 1 }; currentIndex < array.size(); ++currentIndex)
        {
            // If the current element is smaller than our previously found smallest
            if (array[currentIndex] < array[smallestIndex])
            {
                // This is the new smallest number for this iteration
                smallestIndex = currentIndex;
            }
        }

        // Swap our start element with our smallest element
        std::swap(array[startIndex], array[smallestIndex]);
    }

    // Now print our sorted array as proof it works
    for (std::size_t index{ 0 }; index < array.size(); ++index)
    {
        std::cout << array[index] << ' ';
    }
    std::cout << '\n';

    return 0;
}
