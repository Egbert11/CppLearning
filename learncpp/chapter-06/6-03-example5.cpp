// ============================================================
// 来源小节：6.3 Remainder and Exponentiation
// 示例说明：powint_safe()——带溢出检查的整数幂版本（较慢）。
//           溢出时返回 std::numeric_limits<std::int64_t>::max() 并输出错误信息。
// 原文链接：https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/
// 备注：本节代码为按原文描述忠实重建。
//   main 打印 7^12（=13841287201）与 70^12（溢出，返回 int64 最大值）。
// ============================================================
#include <cassert>   // for assert
#include <cstdint>   // for std::int64_t
#include <iostream>
#include <limits>    // for std::numeric_limits

// --- 原文示例片段 ---
// A safer (but slower) version of powint() that checks for overflow
// Returns std::numeric_limits<std::int64_t>::max() if overflow occurs
constexpr std::int64_t powint_safe(std::int64_t base, int exp)
{
    assert(exp >= 0 && "powint_safe: exp parameter has negative value");

    // Handle 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result { 1 };

    // To make the range checking simpler, we'll do all math with positive numbers
    bool negativeResult{ false };
    if (base < 0)
    {
        base = -base;
        negativeResult = (exp & 1);
    }

    while (exp > 0)
    {
        if (exp & 1) // if exp is odd
        {
            // We need to check if result * base will overflow
            if (result > std::numeric_limits<std::int64_t>::max() / base)
            {
                std::cerr << "powint_safe(): result overflowed\n";
                return std::numeric_limits<std::int64_t>::max();
            }

            result *= base;
        }

        exp /= 2;

        // If we're done, we can break
        if (exp <= 0)
            break;

        // The following block will check if base * base will overflow
        if (base > std::numeric_limits<std::int64_t>::max() / base)
        {
            std::cerr << "powint_safe(): base overflowed\n";
            return std::numeric_limits<std::int64_t>::max();
        }

        base *= base;
    }

    if (negativeResult)
        return -result;

    return result;
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << powint_safe(7, 12) << '\n'; // 7 to the 12th power
    std::cout << powint_safe(70, 12) << '\n'; // 70 to the 12th power (will return the max 64-bit int value)

    return 0;
}
