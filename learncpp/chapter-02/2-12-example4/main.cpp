// 来源小节：2.12 Header guards（课后测验的配套调用文件）
// 示例说明：使用带 guard 的 add.h。预期输出：The sum of 3 and 4 is 7
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-guards/
//
// 编译：g++ -std=c++20 -Wall 2-12-example4/main.cpp 2-12-example4/add.cpp -o main

#include "add.h"
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
