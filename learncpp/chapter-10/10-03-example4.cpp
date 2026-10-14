// 来源小节：10.3 Numeric conversions
// 示例说明：有损（lossy）转换：double -> int 丢小数；double -> float 丢精度；
//           以及有损往返的结果（对应原文示例 10、11、12）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeric-conversions/
//
// 编译：g++ -std=c++20 -Wall 10-03-example4.cpp -o a
// 预期输出：
//   3
//   3
//   1.2
//   1.23457
//   3
//   1.23457
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段（double -> int） ---
    int i = 3.0; // okay: will be converted to int value 3 (value preserved)
    int j = 3.5; // data lost: will be converted to int value 3 (fractional value 0.5 lost)
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（double -> float） ---
    float f = 1.2;        // okay: will be converted to float value 1.2 (value preserved)
    float g = 1.23456789; // data lost: will be converted to float 1.23457 (precision lost)
    // --- 原文示例片段结束 ---

    std::cout << i << '\n';
    std::cout << j << '\n';
    std::cout << f << '\n';
    std::cout << g << '\n';

    // --- 原文示例片段（有损往返） ---
    double d{ static_cast<double>(static_cast<int>(3.5)) }; // convert double 3.5 to int and back
    double d2{ static_cast<double>(static_cast<float>(1.23456789)) }; // convert double 1.23456789 to float and back
    // --- 原文示例片段结束 ---

    std::cout << d << '\n';
    std::cout << d2 << '\n';

    return 0;
}
