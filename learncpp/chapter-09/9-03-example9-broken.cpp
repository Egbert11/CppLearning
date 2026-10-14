// 来源小节：9.3 Common semantic errors in C++
// 示例说明：意外的整数除法——两个整数相除得到整数结果，小数部分被截断。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example9-broken.cpp -o a
// 预期输出：5 divided by 3 is: 1
//
// 本节代码为按原文描述重建。本文件演示有意的语义错误（坏实践）。
// 说明：若要得到 1.66667，需用 static_cast<double>(x) / y 之类的写法。

#include <iostream>

int main()
{
    int x{ 5 };
    int y{ 3 };

    std::cout << x << " divided by " << y << " is: " << x / y << '\n'; // integer division

    return 0;
}
