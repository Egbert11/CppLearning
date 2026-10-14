// 来源小节：10.4 Narrowing conversions, list initialization, and constexpr initializers
// 示例说明：constexpr 例外条款。n1 是 constexpr 5，转成 unsigned 后值不变，不算窄化，
//           可以通过；n2 是 constexpr -5，转成 unsigned 会改变值，属于窄化，编译失败。
//           编译器报错形如：error: narrowing conversion of '-5' from 'int' to 'unsigned int'
// 原文链接：https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/
//
// 编译：g++ -std=c++20 -Wall 10-04-example5-error.cpp -o a   （预期编译失败，因 n2 一行）
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    constexpr int n1{ 5 };  // note: constexpr
    unsigned int u1{ n1 };  // okay: conversion is not narrowing due to exclusion clause

    constexpr int n2{ -5 }; // note: constexpr
    unsigned int u2{ n2 };  // compile error: conversion is narrowing due to value change
    // --- 原文示例片段结束 ---

    std::cout << u1 << ' ' << u2 << '\n';

    return 0;
}
