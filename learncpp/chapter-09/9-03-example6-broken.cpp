// 来源小节：9.3 Common semantic errors in C++
// 示例说明：运算符优先级错误——!x > y 实际按 (!x) > y 求值（! 的结合更紧），
//           作者本意多半是 !(x > y)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example6-broken.cpp -o a
// 预期输出：5 is greater than 7
//
// 本节代码为按原文描述重建。本文件演示有意的语义错误（坏实践）。
// 说明：!x 为 0，0 > 7 为 false，于是走 else 分支打印错误信息。

#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 7 };

    if (!x > y) // oops: operator precedence issue (evaluated as (!x) > y)
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';

    return 0;
}
