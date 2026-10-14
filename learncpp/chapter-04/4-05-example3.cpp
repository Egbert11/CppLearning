// 来源小节：4.5 Unsigned integers, and why to avoid them
// 示例说明：另一个方向的回绕 —— 从 0 之下回绕。-1 变成 65535，-2 变成 65534。
//           原文输出：
//             x was: 0
//             x is now: 65535
//             x is now: 65534
//           注意：这是著名的回绕演示，属良定义行为（模运算），但 -Wall 可能给出转换/截断警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
//
// 编译：g++ -std=c++20 -Wall 4-05-example3.cpp -o a

#include <iostream>

int main()
{
    unsigned short x{ 0 }; // smallest 2-byte unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = -1; // -1 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    x = -2; // -2 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    return 0;
}
