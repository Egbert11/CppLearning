// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：分号陷阱——while 条件后误加分号，循环体变成空语句，count 永不递增，
//           程序看起来像"挂住"了。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example7-infinite.cpp -o a
//
// 本节代码为按原文描述重建（同时表达原文示例 7 与示例 8——示例 8 用等价写法显式展示
// 空语句与不再关联的花括号块）。
//
// 警告：本程序永远不会结束。请勿直接运行（或运行后手动终止）。

#include <iostream>

int main()
{
    int count{ 1 };
    while (count <= 10); // oops! this semicolon means the loop body is a null statement
    {
        // 下面这个块已经不再属于 while 循环
        std::cout << count << ' ';
        ++count;
    }

    std::cout << "done!\n"; // never reached

    return 0;
}
