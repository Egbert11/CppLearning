// 来源小节：4.5 Unsigned integers, and why to avoid them
// 示例说明：自最大值之上的无符号回绕（modulo wrap-around）。65536 超出 16 位无符号范围，被模成 0；65537 变成 1。
//           原文输出：
//             x was: 65535
//             x is now: 0
//             x is now: 1
//           注意：给无符号类型赋越界值属良定义行为（回绕），但 -Wall 可能给出溢出/截断警告；
//           若开启“把警告当作错误”，需要临时关闭才能编译运行本例。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
//
// 编译：g++ -std=c++20 -Wall 4-05-example2.cpp -o a

#include <iostream>

int main()
{
    unsigned short x{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = 65536; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    x = 65537; // 65537 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    return 0;
}
