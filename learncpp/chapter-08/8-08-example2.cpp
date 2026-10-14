// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：最基本的 while 循环——从 1 数到 10。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example2.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   1 2 3 4 5 6 7 8 9 10 done!

#include <iostream>

int main()
{
    int count{ 1 };
    while (count <= 10)
    {
        std::cout << count << ' ';
        ++count;
    }

    std::cout << "done!\n";

    return 0;
}
