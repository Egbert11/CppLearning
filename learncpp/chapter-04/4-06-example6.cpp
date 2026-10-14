// 来源小节：4.6 Fixed-width integers and size_t
// 示例说明：打印 sizeof(int)。原文在作者机器上输出：4
// 原文链接：https://www.learncpp.com/cpp-tutorial/fixed-width-integers-and-size-t/
//
// 编译：g++ -std=c++20 -Wall 4-06-example6.cpp -o a

#include <iostream>

int main()
{
    std::cout << sizeof(int) << '\n';

    return 0;
}
