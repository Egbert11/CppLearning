// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：符号转换——值不可表示时的行为（假设 32 位 int）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 预期输出（C++20 起）：
//   4294967295
//   -1
// 注意：无符号转有符号且值不可表示时，C++20 之前为实现定义行为。

#include <iostream>

int main()
{
    int s { -1 };
    std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295

    unsigned int u { 4294967295 }; // largest 32-bit unsigned int
    std::cout << static_cast<int>(u) << '\n'; // implementation-defined prior to C++20, -1 as of C++20

    return 0;
}
