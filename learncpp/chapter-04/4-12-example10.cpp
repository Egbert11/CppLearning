// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：std::int8_t 在输出时表现为 char（大多数编译器把它当作 signed char）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 预期输出：通常是 A（某些系统上可能是 65）

#include <cstdint>
#include <iostream>

int main()
{
    std::int8_t myInt{65};      // initialize myInt with value 65
    std::cout << myInt << '\n'; // you're probably expecting this to print 65

    return 0;
}
