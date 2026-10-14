// 来源小节：4.6 Fixed-width integers and size_t
// 示例说明：sizeof 返回的值类型是 std::size_t，因此用 std::size_t 来接收它。
//           原文在作者机器上输出：4
// 原文链接：https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
//
// 编译：g++ -std=c++20 -Wall 4-06-example7.cpp -o a

#include <cstddef>  // for std::size_t
#include <iostream>

int main()
{
    int x { 5 };
    std::size_t s { sizeof(x) }; // sizeof returns a value of type std::size_t, so that should be the type of s
    std::cout << s << '\n';

    return 0;
}
