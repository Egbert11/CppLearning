// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 2 —— 带替换文本的对象式宏。预处理后 MY_NAME 会被替换为 "Alex"。
//           预期输出：My name is: Alex
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example2.cpp -o a

#include <iostream>

#define MY_NAME "Alex"

int main()
{
    std::cout << "My name is: " << MY_NAME << '\n';

    return 0;
}
