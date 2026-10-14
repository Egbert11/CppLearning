// 来源小节：2.11 Header files
// 示例说明：add() 的定义所在文件。源文件应当 #include 与它配对的头文件，
//           这样声明与定义不一致时编译器能立刻报错（而不是拖到链接期）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-files/
//
// 编译：g++ -std=c++20 -Wall 2-11-example1/main.cpp 2-11-example1/add.cpp -o main

#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.

int add(int x, int y)
{
    return x + y;
}
