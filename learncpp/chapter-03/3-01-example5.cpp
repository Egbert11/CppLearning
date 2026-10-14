// 来源小节：3.1 Syntax and semantic errors
// 示例说明：运行期语义错误——函数本应做加法却用了减法运算符（x - y）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/
//
// 说明：本节示例为按原文描述重建。该程序含原文故意保留的 bug（这正是被调试的对象）。
//
// 预期输出：
//   2
// （注：5 + 3 本应为 8，但因运算符写错而得到 2。）

#include <iostream>

int add(int x, int y) // this function is supposed to perform addition
{
    return x - y; // but it doesn't, due to the wrong operator being used
}

int main()
{
    std::cout << add(5, 3) << '\n'; // should produce 8, but produces 2

    return 0;
}
