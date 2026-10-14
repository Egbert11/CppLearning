// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：无符号数倒计时的 bug——unsigned 类型的 count >= 0 永远为真，
//           减到 0 之后会回绕成 4294967295，形成无限循环。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example10-infinite.cpp -o a
//       （若额外加 -Wextra，会得到 warning: comparison of unsigned expression >= 0 is always true
//        [-Wtype-limits]，正说明该条件恒为真）
//
// 本节代码为按原文描述重建。
// 警告：本程序在打印 "10 9 8 ... 1 blastoff!" 之后不会结束，而是从 4294967295 继续倒着打印
//       （这个值依实现/平台而定，这里假设 32 位 unsigned int）。请勿直接运行。

#include <iostream>

int main()
{
    unsigned int count{ 10 };
    while (count >= 0) // this condition is always true for unsigned values
    {
        std::cout << count << ' ';
        --count;
    }

    return 0;
}
