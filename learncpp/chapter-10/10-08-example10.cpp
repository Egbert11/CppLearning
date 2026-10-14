// 来源小节：10.8 Type deduction for objects using the auto keyword
// 示例说明：可读性/对齐对比——使用 auto 时变量名更容易垂直对齐，逻辑更突出。
//           （对应原文示例 12）
// 原文链接：https://www.learncpp.com/cpp-tutorial/type-deduction-for-objects-using-the-auto-keyword/
//
// 编译：g++ -std=c++20 -Wall 10-08-example10.cpp -o a
// 预期输出：5 6.7 5 6.7
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    // 显式类型：类型名长短不一，变量名不易对齐
    int a{ 5 };
    double b{ 6.7 };

    // 使用 auto：类型信息淡化，变量名对齐，逻辑更突出
    auto c{ 5 };
    auto d{ 6.7 };

    std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';

    return 0;
}
