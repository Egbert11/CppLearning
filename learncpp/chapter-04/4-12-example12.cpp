// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：std::int8_t 的控制台输入被当作字符读取（不是数字）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 示例运行：
//   Enter a number between 0 and 127: 35
//   You entered: 51
// （因为字符 '3' 的 ASCII 码是 51）

#include <cstdint>
#include <iostream>

int main()
{
    std::cout << "Enter a number between 0 and 127: ";
    std::int8_t myInt{};
    std::cin >> myInt;

    std::cout << "You entered: " << static_cast<int>(myInt) << '\n';

    return 0;
}
