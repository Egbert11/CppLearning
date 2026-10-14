// 来源小节：4.11 Chars
// 示例说明：多字符字面量错误——把 '!\n' 当成字面量，作者机器上打印出 58458。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 作者机器上的输出：The value of x is 58458（期望是 "The value of x is 5!"）
// 注意：'!\n' 的值为实现定义（0x210A=8458），本代码**故意演示问题**。

#include <iostream>

int main()
{
    int x { 5 };
    std::cout << "The value of x is " << x << '!\n'; // '!\n' is a multicharacter literal (wrong)

    return 0;
}
