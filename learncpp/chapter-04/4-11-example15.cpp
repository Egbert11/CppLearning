// 来源小节：4.11 Chars
// 示例说明：正确的换行输出（对照上一个错误示例）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 输出：The value of x is 5

#include <iostream>

int main()
{
    int x { 5 };
    std::cout << "The value of x is " << x << '\n';

    return 0;
}
