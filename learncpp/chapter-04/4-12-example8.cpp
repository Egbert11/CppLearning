// 来源小节：4.12 Introduction to type conversion and static_cast
// 示例说明：符号转换——值在两种类型中都可表示时保持不变，只是类型改变。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-type-conversion-and-static_cast/
// 预期输出：
//   5
//   5

#include <iostream>

int main()
{
    unsigned int u1 { 5 };
    // Convert value of u1 to a signed int
    int s1 { static_cast<int>(u1) };
    std::cout << s1 << '\n'; // prints 5

    int s2 { 5 };
    // Convert value of s2 to an unsigned int
    unsigned int u2 { static_cast<unsigned int>(s2) };
    std::cout << u2 << '\n'; // prints 5

    return 0;
}
