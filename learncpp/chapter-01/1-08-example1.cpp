// 来源小节：1.8 Whitespace and basic formatting
// 示例说明：演示“必须有空白分隔”（int 与 x），以及空白数量任意、类型名与变量名可分行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/whitespace-and-basic-formatting/
//
// 编译：g++ -std=c++20 -Wall 1-08-example1.cpp -o example1

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x; // int and x must be whitespace separated
    // --- 原文示例片段结束 ---

    // 少了分隔，intx 会被编译器当成一个标识符，从而报“未知标识符”错误：
    // intx; // error: unknown identifier

    // --- 原文示例片段 ---
    int                y; // 空白数量不限，任意多个都可以
    int
    z; // 类型名与变量名之间换行也可以
    // --- 原文示例片段结束 ---

    // 原文片段：int main(); // int and main must be whitespace separated
    // 因本文件中已有 main 定义，这里仅以注释保留。

    x = 1;
    y = 2;
    z = 3;
    std::cout << x << ' ' << y << ' ' << z << '\n';
    return 0;
}
