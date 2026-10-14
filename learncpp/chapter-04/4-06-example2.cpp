// 来源小节：4.6 Fixed-width integers and size_t
// 示例说明：使用固定宽度 std::int32_t，x 在任何架构上都保证是 32 位，因此 32768 总能容纳。
//           原文输出：32768
// 原文链接：https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
//
// 编译：g++ -std=c++20 -Wall 4-06-example2.cpp -o a

#include <cstdint> // for fixed-width integers
#include <iostream>

int main()
{
    std::int32_t x { 32767 }; // x is always a 32-bit integer
    x = x + 1;                // so 32768 will always fit
    std::cout << x << '\n';

    return 0;
}
