// 来源小节：2.7 Forward declarations and definitions
// 示例说明：声明示例 —— 函数声明告知编译器有一个名为 add 的函数；
//           变量声明告知编译器有一个名为 x 的整数变量。
//           （注意：全局的 int x; 在 C++ 中同时也是定义，此处仅演示“声明”的语法形态。）
// 原文链接：https://www.learncpp.com/cpp-tutorial/forward-declarations/
//
// 编译：g++ -std=c++20 -Wall 2-07-example7.cpp -o a

#include <iostream>

// --- 原文示例片段 ---
int add(int x, int y); // tells the compiler about a function named "add" that takes two int parameters and returns an int.  No body!
int x;                 // tells the compiler about an integer variable named x
// --- 原文示例片段结束 ---

int main()
{
    x = 5;
    std::cout << add(3, 4) << '\n';
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
