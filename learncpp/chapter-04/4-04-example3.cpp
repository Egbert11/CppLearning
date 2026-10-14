// 来源小节：4.4 Signed integers
// 示例说明：有符号整数溢出（未定义行为）。x = x + 1 越过 4 字节 int 的最大值。
//           原文在作者机器上的输出（第二行由未定义行为产生，其他机器可能不同）：
//             2147483647
//             -2147483648
//           注意：这是未定义行为，输出依实现而定，不要依赖具体数值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/signed-integers/
//
// 编译：g++ -std=c++20 -Wall 4-04-example3.cpp -o a

#include <iostream>

int main()
{
    // assume 4 byte integers
    int x { 2'147'483'647 }; // the maximum value of a 4-byte signed integer
    std::cout << x << '\n';

    x = x + 1; // integer overflow, undefined behavior
    std::cout << x << '\n';

    return 0;
}
