// 来源小节：2.8 Programs with multiple code files
// 示例说明：多文件程序示例（main.cpp）。通过前置声明告诉编译器 add() 定义在别的文件里。
// 原文链接：https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/
//
// 编译：g++ -std=c++20 -Wall 2-08-example1/main.cpp 2-08-example1/add.cpp -o main

#include <iostream>

int add(int x, int y); // needed so main.cpp knows that add() is a function defined elsewhere

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}
