// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 12 —— 在函数内部写 #define 与写在函数外部效果完全一样，
//           因为预处理器不理解"函数"这一概念。预期输出：My name is: Alex
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example12.cpp -o a

#include <iostream>

void foo()
{
#define MY_NAME "Alex"
}

int main()
{
    std::cout << "My name is: " << MY_NAME << '\n';

    return 0;
}
