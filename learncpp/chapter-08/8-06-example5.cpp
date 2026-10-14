// 来源小节：8.6 Switch fallthrough and scoping
// 示例说明：对照片段——if 语句后面那条单独的语句被"隐式地"视作位于一个块中。
// 原文链接：https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
//
// 编译：g++ -std=c++20 -Wall 8-06-example5.cpp -o a
//
// 本节代码为按原文描述重建（原文为片段，此处补 main 与变量）。

#include <iostream>

int main()
{
    int x{ 15 };

    // --- 原文示例片段 ---
    if (x > 10)
        std::cout << x << " is greater than 10\n"; // this line implicitly considered to be inside a block
    // --- 原文示例片段结束 ---

    return 0;
}
