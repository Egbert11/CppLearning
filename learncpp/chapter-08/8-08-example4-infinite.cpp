// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：意外的无限循环——忘了递增 count，条件永远不会变为假。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example4-infinite.cpp -o a
//
// 本节代码为按原文描述重建。
// 警告：本程序永远不会结束，会一直打印 "1 1 1 ..."。请勿直接运行（或运行后手动终止）。
//       原文说明：循环头顶那行会反复执行，而它后面的语句永远不会被执行。

#include <iostream>

int main()
{
    int count{ 1 };
    while (count <= 10) // this condition will never be false...
    {
        std::cout << count << ' '; // so this line will repeatedly execute
    }

    std::cout << "done!\n"; // this line will never execute

    return 0;
}
