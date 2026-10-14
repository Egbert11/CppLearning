// 来源小节：10.4 Narrowing conversions, list initialization, and constexpr initializers
// 示例说明：花括号初始化拒绝窄化转换 —— int i { 3.5 } 中 3.5 是 double，
//           转成 int 会丢小数，编译失败。
//           编译器报错形如（Visual Studio）：
//             error C2397: conversion from 'double' to 'int' requires a narrowing conversion
//           （GCC 下形如 narrowing conversion of '3.5e+0' from 'double' to 'int'）
// 原文链接：https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/
//
// 编译：g++ -std=c++20 -Wall 10-04-example2-error.cpp -o a   （预期编译失败）
//
// 本节代码为按原文描述重建。

int main()
{
    // --- 原文示例片段 ---
    int i{ 3.5 }; // won't compile
    // --- 原文示例片段结束 ---

    return 0;
}
