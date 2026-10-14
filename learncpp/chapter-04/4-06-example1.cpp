// 来源小节：4.6 Fixed-width integers and size_t
// 示例说明：假定 int 尺寸会导致移植性问题。int 可能是 16 位或 32 位。
//           原文描述：在 32 位 int 的机器上打印 32768；在 16 位 int 的机器上赋值溢出（未定义行为）并打印 -32768。
//           注意：结果依实现而定，不要依赖具体数值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
//
// 编译：g++ -std=c++20 -Wall 4-06-example1.cpp -o a

#include <iostream>

int main()
{
    int x { 32767 };        // x may be 16-bits or 32-bits
    x = x + 1;              // 32768 overflows if int is 16-bits, okay if int is 32-bits
    std::cout << x << '\n'; // what will this print?

    return 0;
}
