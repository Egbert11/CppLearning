// 来源小节：7.10 Sharing global constants across multiple files (using inline variables)
// 示例说明：方式三 —— main.cpp，用法不变；此头文件可被任意多个文件包含而每个变量只实例化一次。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 7）。
// 需交互输入半径。输入 2 时预期输出：The circumference is: 12.5664
// 编译：g++ -std=c++20 -Wall 7-10-example3/main.cpp -o main

#include "constants.h"

#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    int radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2.0 * constants::pi * radius << '\n';

    return 0;
}
