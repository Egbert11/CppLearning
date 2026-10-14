// ============================================================
// 来源小节：16.x Chapter 16 summary and quiz —— 测验 4 解答
// 示例说明：在测验 3 的基础上改造为交互式：不断读入整数直到 -1，
//           打印该 vector 及其最小/最大元素的下标与值；并处理空 vector 的情形。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/
// 预期输出（示例会话，空 vector 情形）：
//   Enter numbers to add (use -1 to stop): -1
//   No numbers were entered.
// 备注：本节代码为按原文描述重建。交互式程序，需要 stdin 输入。
// ============================================================
#include <cassert>
#include <iostream>
#include <limits>
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
    std::cout << "Enter numbers to add (use -1 to stop): ";

    std::vector<int> v {};

    while (true)
    {
        int x {};
        std::cin >> x;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (x == -1)
            break;

        v.push_back(x);
    }

    if (v.empty())
    {
        std::cout << "No numbers were entered.\n";
        return 0;
    }

    printArray(v);

    auto [minIndex, maxIndex] { findMinMaxIndices(v) };
    std::cout << "The min element has index " << minIndex << " and value " << v[minIndex] << '\n';
    std::cout << "The max element has index " << maxIndex << " and value " << v[maxIndex] << '\n';

    return 0;
}
