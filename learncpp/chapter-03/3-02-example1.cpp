// 来源小节：3.2 The debugging process
// 示例说明：语义错误示例——名为 add 的函数本应做加法，却使用了减法运算符。
//           该程序含原文故意保留的 bug（这正是被调试的对象），输出与原文记录一致。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-debugging-process/
//
// 预期输出（有 bug 时）：
//   5 + 3 = 2
// （注：正确结果应为 8，但函数的运算符写错，故输出 2。）

#include <iostream>

int add(int x, int y) // this function is supposed to perform addition
{
    return x - y; // but it doesn't, due to the wrong operator being used
}

int main()
{
    std::cout << "5 + 3 = " << add(5, 3) << '\n'; // should produce 8, but produces 2

    return 0;
}
