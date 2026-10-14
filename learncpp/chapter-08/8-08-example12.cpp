// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：通过辅助函数实现的"嵌套"循环——外层循环调用一个内部含循环的函数。
//           内层变量 inner 在函数块内，每次外层迭代都会重新创建并初始化为 1。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example12.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   1
//   1 2
//   1 2 3
//   1 2 3 4
//   1 2 3 4 5

#include <iostream>

void printUpto(int outer)
{
    int inner{ 1 }; // inner is created and destroyed at the end of the block
    while (inner <= outer)
    {
        std::cout << inner << ' ';
        ++inner;
    }
}

int main()
{
    int outer{ 1 };
    while (outer <= 5)
    {
        printUpto(outer);
        std::cout << '\n';
        ++outer;
    }

    return 0;
}
