// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：本节 quiz 第 3 题解答——用嵌套 while 打印倒三角。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example15-quiz.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   5 4 3 2 1
//   4 3 2 1
//   3 2 1
//   2 1
//   1

#include <iostream>

int main()
{
    int outer{ 5 };
    while (outer >= 1)
    {
        int inner{ outer };
        while (inner >= 1)
        {
            std::cout << inner-- << ' ';
        }

        std::cout << '\n';
        --outer;
    }

    return 0;
}
