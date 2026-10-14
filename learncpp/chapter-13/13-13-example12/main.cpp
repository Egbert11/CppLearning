// ============================================================
// 来源小节：13.13 Class templates
// 文件说明：main.cpp 包含 pair.h，实例化 Pair<double>，并调用 foo()（原 Example 16）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-templates/
// 编译：g++ -std=c++20 -Wall 13-13-example12/*.cpp -o example12
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include "pair.h"

#include <iostream>

void foo(); // forward declaration of function foo()

int main()
{
    Pair<double> p2{ 1.2, 3.4 }; // instantiates Pair<double> and creates object p2
    std::cout << max(p2) << " is larger\n"; // calls function template max<double>

    foo(); // calls function foo() from foo.cpp

    return 0;
}

// 预期输出：
// 3.4 is larger
// 6 is larger
