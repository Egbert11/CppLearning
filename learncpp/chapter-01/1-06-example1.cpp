// 来源小节：1.6 Uninitialized variables and undefined behavior
// 示例说明：定义一个未初始化的 int 并打印它，用于演示未定义行为（UB）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/uninitialized-variables-and-undefined-behavior/
//
// ※※※ 注意 ※※※
// 本程序可编译通过，但【输出是未定义的】。读取未初始化的变量属于未定义行为。
// 原文示例在不同运行中打印出 7177728、5277592 等任意值；在 Visual Studio 调试配置下
// 则稳定打印 -858993460（因为调试版会把内存置为预设值），但发布版不会。
// 无论结果如何，都不要依赖这个值。g++ -Wall 通常会给出 "is used uninitialized" 警告。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x; // this variable is uninitialized because we haven't given it a value

    std::cout << x << '\n'; // who knows what we'll get, because x is uninitialized
    // --- 原文示例片段结束 ---

    return 0;
}
