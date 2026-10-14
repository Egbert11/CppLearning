// 来源小节：4.5 Unsigned integers, and why to avoid them
// 示例说明：函数参数陷阱 —— 把 -1 传给接收 unsigned int 的函数，会静默转换为 4294967295。
//           原文描述：-1 被隐式转换成 4294967295，程序因此行为异常（试图“运行代码 x 次”时循环几乎永不结束）。
//           输出：x is 4294967295
//           注意：除非激进开启有符号/无符号转换警告（如 -Wsign-conversion），编译器可能完全不报警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unsigned-integers-and-why-to-avoid-them/
//
// 编译：g++ -std=c++20 -Wall 4-05-example7.cpp -o a

#include <iostream>

// assume int is 4 bytes
void doSomething(unsigned int x)
{
    // Run some code x times

    std::cout << "x is " << x << '\n';
}

int main()
{
    doSomething(-1);

    return 0;
}
