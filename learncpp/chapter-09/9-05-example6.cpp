// 来源小节：9.5 std::cin and handling invalid input
// 示例说明：错误情形 4（数值溢出）演示——把超出范围的 40000 读进 std::int16_t，
//           std::cin 进入失败模式并把最接近的合法值 32767 赋给它；第二次提取失败，
//           y 保持初始化的 0，于是输出 "The sum is: 32767"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
//
// 编译：g++ -std=c++20 -Wall 9-05-example6.cpp -o a
// 这是交互式程序，需要用户输入。
// 第一个数输入 40000 时预期输出：The sum is: 32767
//
// 本节代码为按原文描述重建（原文示例 11）。

#include <cstdint>
#include <iostream>

int main()
{
    std::int16_t x{}; // x is 16 bits, holds from -32768 to 32767
    std::cout << "Enter a number between -32768 and 32767: ";
    std::cin >> x;

    std::int16_t y{}; // y is 16 bits, holds from -32768 to 32767
    std::cout << "Enter another number between -32768 and 32767: ";
    std::cin >> y;

    std::cout << "The sum is: " << x + y << '\n';

    return 0;
}
