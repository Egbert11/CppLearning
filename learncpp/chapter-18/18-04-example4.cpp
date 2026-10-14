// ============================================================
// 来源小节：18.4 Timing your code
// 示例说明：用同一份 10000 元素的逆序数据，改用标准库排序 std::ranges::sort
//           计时，与手写选择排序对比。作者机器上约 0.0007 秒，比手写快约 100 倍。
// 原文链接：https://www.learncpp.com/cpp-tutorial/timing-your-code/
// 预期输出：Time taken: <约 0.0007> seconds（约 0.000693/0.000692/0.000699）
// 备注：本节代码为按原文描述重建；使用 C++20 的 std::ranges::sort。
// ============================================================
#include <algorithm> // for std::ranges::sort
#include <array>
#include <chrono>
#include <iostream>
#include <numeric> // for std::iota

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

int main()
{
    std::array<int, g_arrayElements> array;
    std::iota(array.rbegin(), array.rend(), 1); // fill the array with values 10000 to 1

    Timer t;

    std::ranges::sort(array); // Since C++20
    // If your compiler isn't C++20 capable, use std::sort(array.begin(), array.end());

    std::cout << "Time taken: " << t.elapsed() << " seconds\n";

    return 0;
}
