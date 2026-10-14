// 来源小节：10.3 Numeric conversions
// 示例说明：浮点精度损失——double 字面量 0.123456789 有 9 位有效数字，而 float
//           只能支持约 7 位，存进 float 后再用 setprecision(9) 打印可见精度丢失。
//           （对应原文示例 16）
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeric-conversions/
//
// 编译：g++ -std=c++20 -Wall 10-03-example8.cpp -o a
// 预期输出：0.123456791
//
// 本节代码为按原文描述重建。

#include <iomanip>  // for std::setprecision
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    float f = 0.123456789; // double value 0.123456789 has 9 significant digits, but float can only support about 7
    std::cout << std::setprecision(9) << f << '\n'; // std::setprecision defined in iomanip header
    // --- 原文示例片段结束 ---

    return 0;
}
