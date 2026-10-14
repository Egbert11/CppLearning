// ============================================================
// 来源小节：6.3 Remainder and Exponentiation
// 示例说明：powint()——用平方求幂计算整数幂，输出 7^12 = 13841287201。
// 原文链接：https://www.learncpp.com/cpp-tutorial/remainder-and-exponentiation/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <cassert>   // for assert
#include <cstdint>   // for std::int64_t
#include <iostream>

// --- 原文示例片段 ---
// return the value of base^exp, requires exp >= 0
constexpr std::int64_t powint(std::int64_t base, int exp)
{
    assert(exp >= 0 && "powint: exp parameter has negative value");

    // Handle 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result{ 1 };
    while (exp > 0)
    {
        if (exp & 1) // if exp is odd
            result *= base;
        exp /= 2;
        base *= base;
    }

    return result;
}
// --- 原文示例片段结束 ---

int main()
{
    std::cout << powint(7, 12) << '\n'; // 7 to the 12th power

    return 0;
}
