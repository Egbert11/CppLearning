// ============================================================
// 来源小节：16.x Chapter 16 summary and quiz —— 测验 3 解答
// 示例说明：函数模板 findMinMaxIndices() 返回"最小、最大元素下标"的 pair；
//           printArray() 打印数组；main 分别用 int 与 double 两个 vector 测试。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/
// 预期输出：
//   3, 8, 2, 5, 7, 4, 6
//   The min element has index 2 and value 2
//   The max element has index 1 and value 8
//   1.2, 3.4, 5.6, 7.8
//   The min element has index 0 and value 1.2
//   The max element has index 3 and value 7.8
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t> findMinMaxIndices(const std::vector<T>& v)
{
    assert(v.size() > 0 && "findMinMaxIndices: empty vector");

    std::size_t minIndex { 0 };
    std::size_t maxIndex { 0 };

    for (std::size_t index { 1 }; index < v.size(); ++index)
    {
        if (v[index] < v[minIndex])
            minIndex = index;

        if (v[index] > v[maxIndex])
            maxIndex = index;
    }

    return { minIndex, maxIndex };
}

template <typename T>
void printArray(const std::vector<T>& v)
{
    bool first { true };
    for (const auto& e : v)
    {
        if (!first)
            std::cout << ", ";

        first = false;
        std::cout << e;
    }
    std::cout << '\n';
}

int main()
{
    std::vector testScore1 { 3, 8, 2, 5, 7, 4, 6 };
    printArray(testScore1);

    auto [minIndex1, maxIndex1] { findMinMaxIndices(testScore1) }; // C++17 structured binding
    std::cout << "The min element has index " << minIndex1 << " and value " << testScore1[minIndex1] << '\n';
    std::cout << "The max element has index " << maxIndex1 << " and value " << testScore1[maxIndex1] << '\n';

    std::vector<double> testScore2 { 1.2, 3.4, 5.6, 7.8 };
    printArray(testScore2);

    auto [minIndex2, maxIndex2] { findMinMaxIndices(testScore2) };
    std::cout << "The min element has index " << minIndex2 << " and value " << testScore2[minIndex2] << '\n';
    std::cout << "The max element has index " << maxIndex2 << " and value " << testScore2[maxIndex2] << '\n';

    return 0;
}
