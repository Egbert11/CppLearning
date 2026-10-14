// ============================================================
// 来源小节：18.4 Timing your code
// 示例说明：计时用的 Timer 类。chrono 库直接使用略显晦涩，这个小类把它封装
//           起来：构造时记录起点，reset() 重置起点，elapsed() 返回从起点到
//           现在经过的秒数（double）。
//   类型别名：Clock = std::chrono::steady_clock（单调时钟，适合计时）
//             Second = std::chrono::duration<double, std::ratio<1>>（以秒为单位）
// 原文链接：https://www.learncpp.com/cpp-tutorial/timing-your-code/
// 预期输出：（无输出，仅定义工具类）
// 备注：本节代码为按原文描述重建；该类会在后面几个示例中使用。
// ============================================================
#include <chrono> // for std::chrono functions

class Timer
{
private:
    // Type aliases to make accessing nested type easier
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
    return 0;
}
