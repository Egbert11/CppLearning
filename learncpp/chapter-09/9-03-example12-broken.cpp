// 来源小节：9.3 Common semantic errors in C++
// 示例说明：条件中误用赋值运算符代替相等运算符——c = 'y' 返回 'y'（非零，即为真），
//           因此被守护的调用总会执行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example12-broken.cpp -o a
//       （现代编译器通常会对此给出 warning）
// 输入 n 时预期输出：Kaboom!
//
// 本节代码为按原文描述重建。本文件演示有意的语义错误（坏实践）。

#include <iostream>

void blowUpWorld()
{
    std::cout << "Kaboom!\n";
}

int main()
{
    std::cout << "Should we blow up the world again? (y/n): ";
    char c{};
    std::cin >> c;

    if (c = 'y')   // uses assignment operator instead of equality operator
        blowUpWorld();

    return 0;
}
