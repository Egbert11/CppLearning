// 来源小节：11.3 Function overload resolution and ambiguous matches
// 示例说明：char 实参没有精确匹配（既非 int 也非 double），经数值提升解析到 print(int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/function-overload-resolution-and-ambiguous-matches/
//
// 编译：g++ -std=c++20 -Wall 11-03-example2.cpp -o a
//
// 本节代码为按原文描述重建。
// 注：原文 Example 2 还包含 print(5L)。'a' 会经提升解析到 print(int)，而 long 类型的 5L
//     到 int / double 均为数值转换、彼此无优劣，构成歧义（见 11-03-example9-error.cpp），
//     故这里只保留 print('a') 以得到一个可编译的演示。

#include <iostream>

void print(int x)
{
    std::cout << "print(int): " << x << '\n';
}

void print(double d)
{
    std::cout << "print(double): " << d << '\n';
}

int main()
{
    print('a'); // char does not match int or double exactly; promoted to int -> print(int)

    return 0;
}
