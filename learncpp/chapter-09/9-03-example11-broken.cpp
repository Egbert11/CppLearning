// 来源小节：9.3 Common semantic errors in C++
// 示例说明：缺少复合语句（缺花括号）——if 只守护紧跟的第一条 cout，
//           blowUpWorld() 不在 if 体内，因此总会执行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example11-broken.cpp -o a
// 输入 n 时预期输出：Kaboom!   （即便用户回答 n，世界也被炸毁）
// 输入 y 时预期输出：
//   Blowing up the world ...
//   Kaboom!
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

    if (c == 'y')
        std::cout << "Blowing up the world ...\n"; // only this statement is guarded by the if
        blowUpWorld();                             // always executes (not part of the if)

    return 0;
}
