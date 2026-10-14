// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：下标变量为非 constexpr 的有符号 int 时，需隐式转成 std::size_t，
//           属收窄转换，预期产生警告（-Wsign-conversion）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期警告：warning: conversion to 'std::size_t' from 'int' may change the sign of the result
// 预期输出：7
// 备注：本文件为预期产生警告示例（-warning）。用 -Wall 不一定报，可加 -Wsign-conversion 复现。
// ============================================================
#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    int index { 3 };                   // non-constexpr signed value
    std::cout << prime[index] << '\n'; // possible warning: index implicitly converted to std::size_t, narrowing conversion

    return 0;
}
