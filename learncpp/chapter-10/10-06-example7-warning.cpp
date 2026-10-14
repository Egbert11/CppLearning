// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：i = i / 2.5; 先做浮点除法得到 double，再赋回 int（窄化），可能警告；
//           用 static_cast<int> 显式表达后不再警告。（对应原文示例 11、12）
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
//
// 编译：g++ -std=c++20 -Wall 10-06-example7-warning.cpp -o a
//       预期产生警告（需 GCC 的 -Wconversion，默认不在 -Wall 中）：
//         warning: conversion from 'double' to 'int' may change value [-Wfloat-conversion]
//       （原文为"可能警告"的示例，此处保留该隐式窄化以复现原文结论。）
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段（示例 11） ---
    int i{ 100 };
    i = i / 2.5; // 浮点除法结果为 double 40.0，赋回 int 时窄化
    // --- 原文示例片段结束 ---

    std::cout << i << '\n';

    // --- 原文示例片段（示例 12） ---
    int j{ 100 };
    j = static_cast<int>(j / 2.5); // 显式转换，无警告
    // --- 原文示例片段结束 ---

    std::cout << j << '\n';

    return 0;
}
