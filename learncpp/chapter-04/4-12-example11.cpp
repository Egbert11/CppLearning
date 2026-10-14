// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：把 std::int8_t 转成 int，保证按整数输出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 输出：65

#include <cstdint>
#include <iostream>

int main()
{
    std::int8_t myInt{65};
    std::cout << static_cast<int>(myInt) << '\n'; // will always print 65

    return 0;
}
