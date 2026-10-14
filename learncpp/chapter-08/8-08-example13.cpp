// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：直接嵌套的 while 循环——与示例 12 输出相同，但内层循环直接写在外层循环块内。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example13.cpp -o a
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

int main()
{
    int outer{ 1 };
    while (outer <= 5)
    {
        int inner{ 1 }; // inner is created and destroyed at the end of the block
        while (inner <= outer)
        {
            std::cout << inner << ' ';
            ++inner;
        }

        std::cout << '\n';
        ++outer;
    }

    return 0;
}
