// 来源小节：3.4 Basic debugging tactics
// 示例说明：有 bug 的程序——调用 getValue 时漏写了括号 ()，于是打印的是函数指针而非返回值。
//           该程序含原文故意保留的 bug（这正是被调试的对象），输出与原文记录一致。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
//
// 预期输出（g++ 等把布尔转换规则应用于函数指针时打印 1；某些编译器会打印地址）：
//   1
// （例如 Visual Studio 可能输出类似 00101424 的地址。）

#include <iostream>

int getValue()
{
    return 4;
}

int main()
{
    std::cout << getValue << '\n'; // 漏写了调用括号 ()，打印的是函数指针

    return 0;
}
