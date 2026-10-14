// ============================================================
// 来源小节：18.4 Timing your code
// 示例说明：给本节的选择排序计时——对 10000 个元素排序。数组用 std::iota
//           以逆序迭代器填充，得到从大到小（10000..1）的初始数据，再计时排序。
// 原文链接：https://www.learncpp.com/cpp-tutorial/timing-your-code/
// 预期输出：Time taken: <约 0.05> seconds（作者机器上约 0.0507/0.0506/0.0498）
// 备注：本节代码为按原文描述重建；具体数值随机器而异，请用 release 构建测量。
// ============================================================
#include <algorithm> // for std::swap
#include <array>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <numeric> // for std::iota
#include <utility> // for std::swap

constexpr int g_arrayElements{ 10000 };

class Timer
{
private:
    using Clock = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<Clock> m_beg{ Clock::now() };

public:
    void reset()
    {
        m_beg = Clock::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

void sortArray(std::array<int, g_arrayElements>& array)
{
    // Step through each element of the array
    // (except the last one, which will already be sorted by the time we get there)
    for (std::size_t startIndex{ 0 }; startIndex < (g_arrayElements - 1); ++startIndex)
    {
        // smallestIndex is the index of the smallest element we've encountered so far.
        std::size_t smallestIndex{ startIndex };

        // Look for smallest element remaining in the array (starting at startIndex+1)
        for (std::size_t currentIndex{ startIndex + 1 }; currentIndex < g_arrayElements; ++currentIndex)
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
}

int main()
{
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1); // fill the array with values 10000 to 1

    Timer t;

    sortArray(array);

    std::cout << "Time taken: " << t.elapsed() << " seconds\n";

    return 0;
}
