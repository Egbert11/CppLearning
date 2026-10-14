// 来源小节：8.8 Introduction to loops and while statements
// 示例说明：本节 quiz 第 4 题解答（原文归功于 Shiva）——打印右对齐的数字三角形。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-loops-and-while-statements/
//
// 编译：g++ -std=c++20 -Wall 8-08-example16-quiz.cpp -o a
//
// 本节代码为按原文描述重建。
//
// 原文预期输出：
//           1
//         2 1
//       3 2 1
//     4 3 2 1
//   5 4 3 2 1

#include <iostream>

int main()
{
    int outer{ 1 };
    while (outer <= 5)
    {
        int inner{ 5 };
        while (inner >= 1)
        {
            if (inner <= outer)
                std::cout << inner << ' ';
            else
                std::cout << "  "; // two spaces keep the columns aligned

            --inner;
        }

        std::cout << '\n';
        ++outer;
    }

    return 0;
}
