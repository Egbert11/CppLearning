// 来源小节：9.3 Common semantic errors in C++
// 示例说明：意外的空语句（null statement）——if 条件后多写了一个分号，使被守护的
//           语句脱离条件，blowUpWorld() 无条件执行。
// 原文链接：https://www.learncpp.com/cpp-tutorial/common-semantic-errors-in-c/
//
// 编译：g++ -std=c++20 -Wall 9-03-example10-broken.cpp -o a
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

    if (c == 'y');     // accidental null statement here
        blowUpWorld(); // so this will always execute since it's not part of the if statement

    return 0;
}
