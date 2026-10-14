// 来源小节：5.6 Constexpr variables
// 示例说明：数组长度必须是编译期常量。字面量可以直接作长度；
//           此外“初始化器是常量表达式的 const 整型”也享有一个历史特例，可作数组长度。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-variables/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建。
// 预期输出：
//   5 5

#include <iostream>

int main()
{
    int arr[5] {}; // ok: 5 is a literal known at compile time

    const int arrLen { 5 }; // const integral with a constant-expression initializer
    int arr2[arrLen] {};    // ok: allowed as an array length (special-cased for const integral types)

    std::cout << sizeof(arr) / sizeof(arr[0]) << ' '
              << sizeof(arr2) / sizeof(arr2[0]) << '\n';

    return 0;
}
