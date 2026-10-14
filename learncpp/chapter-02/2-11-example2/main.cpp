// 来源小节：2.11 Header files（Foo.h 的配套源文件，用于让示例可编译）
// 示例说明：演示头文件自己包含所需头文件后，使用方只需 #include "Foo.h" 即可。
//           预期输出：Application name: MyApp
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-files/
//
// 编译：g++ -std=c++20 -Wall 2-11-example2/main.cpp -o main

#include "Foo.h"
#include <iostream>

std::string_view getApplicationName()
{
    return "MyApp";
}

int main()
{
    std::cout << "Application name: " << getApplicationName() << '\n';
    return 0;
}
