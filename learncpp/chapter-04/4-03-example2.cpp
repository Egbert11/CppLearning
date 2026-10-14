// 来源小节：4.3 Object sizes and the sizeof operator
// 示例说明：sizeof 也可以作用于变量名（而不仅是类型）。
//           原文在作者机器上的输出：x is 4 bytes
// 原文链接：https://www.learncpp.com/cpp-tutorial/object-sizes-and-the-sizeof-operator/
//
// 编译：g++ -std=c++20 -Wall 4-03-example2.cpp -o a

#include <iostream>

int main()
{
    int x{};
    std::cout << "x is " << sizeof(x) << " bytes\n";

    return 0;
}
