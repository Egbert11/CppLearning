// 来源小节：4.6 Fixed-width integers and size_t
// 示例说明：8 位固定宽度类型常被当作 char 打印，而非整数。std::int8_t x{65} 很可能不打印 65，而是打印字符 'A'。
//           原文描述：这很可能不会打印 65，原因见 4.11 与 4.12。
// 原文链接：https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
//
// 编译：g++ -std=c++20 -Wall 4-06-example3.cpp -o a

#include <cstdint> // for fixed-width integers
#include <iostream>

int main()
{
    std::int8_t x { 65 };   // initialize 8-bit integral type with value 65
    std::cout << x << '\n'; // You're probably expecting this to print 65

    return 0;
}
