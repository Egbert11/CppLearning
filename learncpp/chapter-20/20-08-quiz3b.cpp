// 来源小节：20.x Chapter 20 summary and quiz（Quiz 3b）
// 示例说明：用递归方式实现二分查找，返回目标元素的下标，找不到返回 -1。
//           base case 是 min > max（目标不存在）；否则比较中点后递归到可能存在目标的半边。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-20-summary-and-quiz/
// 说明：本节代码按原文解答重建（包含原文的测试 harness）。
// 预期输出：10 行 "test value N passed!"（每个测试值一行）。
// Tip（原文）：以后不要手写这个——标准库提供 std::binary_search（判断值是否存在）与
//              std::equal_range（返回匹配范围的起止迭代器）。

#include <cassert>
#include <iostream>
#include <iterator> // for std::size
#include <numeric>  // for std::midpoint (C++20)

// --- 原文解答 ---
int binarySearch(const int* array, int target, int min, int max)
{
    assert(array); // make sure array exists

    if (min > max)
        return -1;

    // int midpoint{ min + ((max - min) / 2) }; // Before C++20: avoids overflow
    int midpoint{ std::midpoint(min, max) };

    if (array[midpoint] > target)
    {
        return binarySearch(array, target, min, midpoint - 1);
    }
    else if (array[midpoint] < target)
    {
        return binarySearch(array, target, midpoint + 1, max);
    }

    return midpoint;
}
// --- 原文解答结束 ---

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // Test values
    constexpr int testValues[]{ 0, 3, 12, 13, 22, 26, 43, 44, 48, 49 };

    // Expected results for those test values
    int expectedResult[]{ -1, 0, 3, -1, -1, 8, -1, 13, 14, -1 };

    // Same number of test values and expected results
    static_assert(std::size(testValues) == std::size(expectedResult));

    int numTestValues{ std::size(testValues) };

    for (int count{ 0 }; count < numTestValues; ++count)
    {
        int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };

        if (index == expectedResult[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}
