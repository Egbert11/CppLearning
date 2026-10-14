// 来源小节：20.1 Function Pointers
// 示例说明：用回调函数（函数指针参数）泛化选择排序：
//           同一个 selectionSort 通过不同的比较函数实现升序、降序、偶数优先等排序。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-pointers/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   9 8 7 6 5 4 3 2 1
//   1 2 3 4 5 6 7 8 9
//   2 4 6 8 1 3 5 7 9

#include <iostream>
#include <utility>

// Here is a comparison function that sorts in ascending order
bool ascending(int x, int y)
{
    return x > y; // swap if the first element is greater than the second
}

// Here is a comparison function that sorts in descending order
bool descending(int x, int y)
{
    return x < y; // swap if the first element is less than the second
}

// --- 原文示例片段 ---
void selectionSort(int* array, int size, bool (*comparisonFcn)(int, int))
{
    // Step through each element of the array
    for (int startIndex{ 0 }; startIndex < (size - 1); ++startIndex)
    {
        // bestIndex is the index of the smallest/largest element we've encountered so far.
        int bestIndex{ startIndex };

        // Look for smallest/largest element remaining in the subarray (starting at startIndex+1)
        for (int currentIndex{ startIndex + 1 }; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller/larger than our previously found smallest
            if (comparisonFcn(array[bestIndex], array[currentIndex])) // COMPARISON DONE HERE
            {
                // This is the new smallest/largest number for this iteration
                bestIndex = currentIndex;
            }
        }

        // Swap our start element with our smallest/largest element
        std::swap(array[startIndex], array[bestIndex]);
    }
}
// --- 原文示例片段结束 ---

// This function prints out the values in the array
void printArray(int* array, int size)
{
    for (int index{ 0 }; index < size; ++index)
    {
        std::cout << array[index] << ' ';
    }

    std::cout << '\n';
}

// --- 原文示例片段 ---
bool evensFirst(int x, int y)
{
    // if x is even and y is odd, x goes first (no swap needed)
    if ((x % 2 == 0) && !(y % 2 == 0))
        return false;

    // if x is odd and y is even, y goes first (swap needed)
    if (!(x % 2 == 0) && (y % 2 == 0))
        return true;

    // otherwise sort in ascending order
    return ascending(x, y);
}
// --- 原文示例片段结束 ---

int main()
{
    int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    // Sort the array in descending order using the descending() function
    selectionSort(array, 9, descending);
    printArray(array, 9);

    // Sort the array in ascending order using the ascending() function
    selectionSort(array, 9, ascending);
    printArray(array, 9);

    // Sort the array so that even numbers come first
    selectionSort(array, 9, evensFirst);
    printArray(array, 9);

    return 0;
}
