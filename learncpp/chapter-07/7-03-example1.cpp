// 来源小节：7.3 Local variables
// 示例说明：块作用域（block scope）——局部变量从定义处到所在块结束处可见。（对应原文 Example 1）
// 原文链接：https://www.learncpp.com/cpp-tutorial/local-variables/
//
// 预期输出：5 4
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{
    int i { 5 };      // i enters scope here
    double d { 4.0 }; // d enters scope here

    std::cout << i << ' ' << d << '\n'; // use i and d

    return 0;
} // i and d go out of scope here
