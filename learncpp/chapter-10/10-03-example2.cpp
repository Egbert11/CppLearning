// 来源小节：10.3 Numeric conversions
// 示例说明：保值（value-preserving）转换及其往返：int 5 -> long，short 5 -> double；
//           再用 static_cast 做往返转换，验证能取回原值（对应原文示例 6、7）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/numeric-conversions/
//
// 编译：g++ -std=c++20 -Wall 10-03-example2.cpp -o a
// 预期输出：
//   5
//   5
//   3
//   c
// 注：double 值 5.0 在默认格式下打印为 "5"。
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段（保值转换） ---
    int n{ 5 };
    long l = n;   // okay, produces long value 5

    short s{ 5 };
    double d = s; // okay, produces double value 5.0
    // --- 原文示例片段结束 ---

    std::cout << l << '\n';
    std::cout << d << '\n';

    // --- 原文示例片段（保值往返） ---
    int n2 = static_cast<int>(static_cast<long>(3)); // convert int 3 to long and back
    char c = static_cast<char>(static_cast<double>('c')); // convert 'c' to double and back
    // --- 原文示例片段结束 ---

    std::cout << n2 << '\n';
    std::cout << c << '\n';

    return 0;
}
