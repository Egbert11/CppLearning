// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：不用循环，硬编码打印 1 到 10 —— 用来对比为什么需要循环（因为 1 到 1000
//           或 1 到用户输入的数都不可能硬编码）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example1.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   1 2 3 4 5 6 7 8 9 10 done!

#include <iostream>

int main()
{
    std::cout << "1 2 3 4 5 6 7 8 9 10";
    std::cout << " done!\n";

    return 0;
}
