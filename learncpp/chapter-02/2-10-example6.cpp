// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 6 —— #ifndef：因为 PRINT_BOB 从未定义，所以 Bob 会被编译。
//           预期输出：Bob
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example6.cpp -o a

#include <iostream>

int main()
{
#ifndef PRINT_BOB
    std::cout << "Bob\n";
#endif

    return 0;
}
