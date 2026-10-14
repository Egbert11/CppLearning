// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：用取余运算符每 10 次迭代做一件事（换行），并给小于 10 的数字补前导 0。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example11.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//   01 02 03 04 05 06 07 08 09 10
//   11 12 13 14 15 16 17 18 19 20
//   21 22 23 24 25 26 27 28 29 30
//   31 32 33 34 35 36 37 38 39 40
//   41 42 43 44 45 46 47 48 49 50

#include <iostream>

int main()
{
    int count{ 1 };
    while (count <= 50)
    {
        // print the number, padding with a zero if it is less than 10
        if (count < 10)
            std::cout << '0';

        std::cout << count << ' ';

        // print a newline every 10th iteration
        if (count % 10 == 0)
            std::cout << '\n';

        ++count;
    }

    return 0;
}
