// ============================================================
// 来源小节：18.4 Timing your code
// 示例说明：Timer 的基本用法骨架——在希望开始计时处构造 Timer，任意时刻
//           调用 elapsed() 得到已过去的秒数。此处把 Timer 类一并放入以便编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/timing-your-code/
// 预期输出：Time elapsed: <很小的数> seconds
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <chrono>
#include <iostream>

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
    Timer t;

    // Code to measure goes here

    std::cout << "Time elapsed: " << t.elapsed() << " seconds\n";

    return 0;
}
