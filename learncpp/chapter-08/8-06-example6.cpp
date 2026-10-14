// 来源小节：8.6 Switch fallthrough and scoping
// 示例说明：对照片段——switch 的标签不创建隐式块，标签后的语句属于 switch 块的作用域。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
//
// 编译：g++ -std=c++20 -Wall 8-06-example6.cpp -o a
//
// 本节代码为按原文描述重建（原文为片段，此处补 foo() 桩函数与 main）。

#include <iostream>

void foo() { std::cout << "foo()\n"; }

int main()
{
    // --- 原文示例片段 ---
    switch (1)
    {
    case 1: // does not create an implicit block
        foo(); // this is part of the switch scope, not an implicit block to case 1
        break; // this is part of the switch scope, not an implicit block to case 1
    default:
        std::cout << "default case\n";
        break;
    }
    // --- 原文示例片段结束 ---

    return 0;
}
