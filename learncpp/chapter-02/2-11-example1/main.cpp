// 来源小节：2.11 Header files
// 示例说明：通过 #include "add.h" 引入 add() 的前置声明，无需在 main.cpp 里手写。
//           预期输出：The sum of 3 and 4 is 7
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-files/
//
// 编译：g++ -std=c++20 -Wall 2-11-example1/main.cpp 2-11-example1/add.cpp -o main

#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
