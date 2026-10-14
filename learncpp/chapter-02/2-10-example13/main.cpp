// 来源小节：2.10 Introduction to the preprocessor（Example 13）
// 示例说明：#include "Alex.h" 会把该头文件里的 #define 复制进来，于是 MY_NAME 被替换为 "Alex"。
//           预期输出：My name is: Alex
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example13/main.cpp -o a

#include "Alex.h" // copies #define MY_NAME from Alex.h here
#include <iostream>

int main()
{
    std::cout << "My name is: " << MY_NAME << '\n'; // preprocessor will convert this to "Alex"

    return 0;
}
