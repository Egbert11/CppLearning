// 来源小节：21.x Chapter 21 summary and quiz（测验 2 解答）
// 示例说明：Average 类跟踪传入整数的平均值。两个成员：累加和（std::int32_t）与计数。
//           重载成员 operator+= 支持 avg += n 与链式 (avg += 6) += 10；
//           友元 operator<< 在未收到任何数时输出 0，否则把总和转成 double 再相除（避免整数除法）。
//           该类无需自定义拷贝构造/赋值（成员逐个复制即可）。用 std::int32_t 而非 int，
//           是因为 int 在某些平台可能只有 16 位，无法容纳较大的累加和。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-21-summary-and-quiz/
// 说明：本节代码为按原文描述重建。
// 预期输出：
//   0
//   4
//   6
//   12
//   6.5
//   7
//   7

#include <cstdint>
#include <iostream>

class Average
{
private:
    std::int32_t m_total{ 0 }; // the sum of all numbers we've seen so far
    std::int8_t m_numbers{ 0 }; // the count of numbers we've seen so far

public:
    Average() = default;

    friend std::ostream& operator<<(std::ostream& out, const Average& average)
    {
        // Our average is the sum of the numbers we've seen divided by the count of the numbers we've seen
        // We need to remember to do a floating point division here, not an integer division
        if (average.m_numbers == 0)
            out << 0;
        else
            out << static_cast<double>(average.m_total) / average.m_numbers;

        return out;
    }

    // Because operator+= is modifying an existing object, we can implement it as a member function
    Average& operator+=(int num)
    {
        m_total += num;
        ++m_numbers;

        return *this;
    }
};

int main()
{
    Average avg{};
    std::cout << avg << '\n'; // 0

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10; // chained, same as avg += 6; avg += 10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{ avg };
    std::cout << copy << '\n'; // 7

    return 0;
}
