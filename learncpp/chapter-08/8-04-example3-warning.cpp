// 来源小节：8.4 Constexpr if statements
// 示例说明：示例 2 经编译器只保留真分支后，"实际上等价于"的程序。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-if-statements/
//
// 编译：g++ -std=c++20 -Wall 8-04-example3-warning.cpp -o a
//       预期产生警告：warning: unused variable 'gravity' [-Wunused-variable]
//       （因为 true 分支保留后 gravity 不再被使用；原文本就如此，此处不额外消除该警告）
//
// 本节代码为按原文描述重建。

#include <iostream>

int main()
{
    constexpr double gravity{ 9.8 };

    std::cout << "Gravity is normal.\n";

    return 0;
}
