// 来源小节：4.11 Chars
// 示例说明：正斜杠错误——把换行误写成多字符字面量 '/n'（实现定义的值，作者机器上为 12142）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 作者机器上的输出：312142（= add(1,2) 的结果 3 拼接 '/n' 的值 12142）
// 注意：'/n' 是多字符字面量，其值由实现定义，不同编译器输出可能不同；这是**故意演示的问题代码**。

#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << add(1, 2) << '/n'; // '/n' is a multicharacter literal (wrong; should be '\n')

    return 0;
}
