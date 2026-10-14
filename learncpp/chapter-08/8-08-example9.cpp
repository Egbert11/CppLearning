// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：有意使用空循环体——反复调用函数直到它返回 false。若它永不返回 false，则是无限循环。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example9.cpp -o a
//
// 本节代码为按原文描述重建（原文为片段，此处补 keepRunning() 桩函数与 main）。

#include <iostream>

bool keepRunning()
{
    static int count{ 0 };
    return ++count <= 3; // 前 3 次返回 true，之后返回 false
}

int main()
{
    // --- 原文示例片段 ---
    while (keepRunning()) // 反复调用，直到返回 false
        ;
    // --- 原文示例片段结束 ---
    // 原文警告：如果 keepRunning() 永远不返回 false，就是无限循环。
    // 注意循环体是一条空语句（分号），这里是有意为之。

    std::cout << "done\n";

    return 0;
}
