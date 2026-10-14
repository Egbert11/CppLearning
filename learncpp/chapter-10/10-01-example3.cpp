// 来源小节：10.1 Implicit type conversion
// 示例说明：汇总隐式转换发生的各种场合：初始化、赋值、返回值、二元运算、
//           if 条件、函数实参（分别对应原文示例 3~7）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/implicit-type-conversion/
//
// 编译：g++ -std=c++20 -Wall 10-01-example3.cpp -o a
//
// 本节代码为按原文描述重建。

#include <iostream>

float returnFloat() // 声明返回 float
{
    double d{ 3.5 };
    return d; // 隐式转换：返回值 double 转成 float
}

void printLong(long l)
{
    std::cout << l << '\n';
}

int main()
{
    // --- 原文示例片段（初始化 / 赋值） ---
    [[maybe_unused]] double d{ 3 }; // int value 3 implicitly converted to type double
    d = 6;         // int value 6 implicitly converted to type double
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（返回值） ---
    std::cout << returnFloat() << '\n'; // 3.5
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（二元运算符混合类型） ---
    double division{ 4.0 / 3 }; // int value 3 implicitly converted to type double
    std::cout << division << '\n'; // 1.33333
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（if 条件中的非布尔值） ---
    if (5) // int value 5 implicitly converted to type bool
    {
        std::cout << "if (5) is true\n";
    }
    // --- 原文示例片段结束 ---

    // --- 原文示例片段（函数实参类型不匹配） ---
    int i{ 7 };
    printLong(i); // int 隐式转换为 long
    // --- 原文示例片段结束 ---

    return 0;
}
