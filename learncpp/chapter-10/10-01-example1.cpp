// 来源小节：10.1 Implicit type conversion
// 示例说明：用 int 3 初始化 float —— 位模式不能照抄，编译器必须把 int 值 3 转换成
//           对应的 float 值 3.0f（产生一个临时 float 对象）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/implicit-type-conversion/
//
// 编译：g++ -std=c++20 -Wall 10-01-example1.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    float f{ 3 }; // initialize floating point variable with int 3
    // --- 原文示例片段结束 ---

    std::cout << f << '\n'; // 3

    return 0;
}
