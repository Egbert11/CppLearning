// ============================================================
// 来源小节：13.3 Unscoped enumerator integral conversions
// 示例说明：枚举量的默认取值规则——第一个枚举量得 0，之后每个都是"前一个 + 1"。
//           因此 Color 的 blue 实际存储整数值 2。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/
// 备注：本节代码为按原文描述忠实重建。原文未展示输出，这里补一句打印以便验证。
// ============================================================
#include <iostream>

enum Color
{
    black,   // 0
    red,     // 1
    blue,    // 2
    green,   // 3
    white,   // 4
    cyan,    // 5
    yellow,  // 6
    magenta, // 7
};

int main()
{
    Color shirt{ blue }; // shirt actually stores integral value 2

    std::cout << "The enum stores: " << shirt << '\n';

    return 0;
}

// 预期输出：
// The enum stores: 2
