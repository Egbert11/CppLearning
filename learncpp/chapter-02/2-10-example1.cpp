// 来源小节：2.10 Introduction to the preprocessor
// 示例说明：原文 Example 1 —— 预处理阶段会把 #include <iostream> 这一行替换为 iostream 文件的全部内容。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/
//
// 编译：g++ -std=c++20 -Wall 2-10-example1.cpp -o a

#include <iostream>

int main()
{
    std::cout << "Hello, world!\n";

    return 0;
}
