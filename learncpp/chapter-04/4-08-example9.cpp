// 来源小节：4.8 Floating point numbers
// 示例说明：用浮点除法演示 IEEE 754 的特殊值：+Inf、-Inf、+0.0、-0.0、NaN。
// 原文链接：https://www.learncpp.com/cpp-tutorial/floating-point-numbers/
// 预期输出（与平台相关，Clang 下）：
//   inf
//   -inf
//   0
//   -0
//   nan
// 注意：Visual Studio 会把 NaN 打印为 -nan(ind)。原文 Best practice 建议避免除以 0.0，
//       本示例仅为演示特殊值。
// 说明：本文件为重建代码。

#include <iostream>

int main()
{
    double zero { 0.0 };

    double posinf { 5.0 / zero }; // positive infinity
    std::cout << posinf << '\n';

    double neginf { -5.0 / zero }; // negative infinity
    std::cout << neginf << '\n';

    double z1 { 0.0 / posinf }; // positive zero
    std::cout << z1 << '\n';

    double z2 { -0.0 / posinf }; // negative zero
    std::cout << z2 << '\n';

    double nan { zero / zero }; // not a number (mathematically invalid)
    std::cout << nan << '\n';

    return 0;
}
