// 来源小节：10.6 Explicit type conversion (casting) and static_cast
// 示例说明：测验 1 解答——隐式转换 vs 显式转换。这里用两段代码并排演示：
//           隐式转换由编译器在类型不匹配时自动完成；显式转换由程序员用 static_cast 要求。
// 原文链接：https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/
//
// 编译：g++ -std=c++20 -Wall 10-06-quiz1.cpp -o a
// 预期输出：
//   implicit: 97
//   explicit: 97
//
// 本文件为按原文解答要点重建。

#include <iostream>

int main()
{
    char c{ 'a' };

    // 隐式转换：把 char 交给期望 int 的输出流，编译器自动把 char 提升为 int
    int implicit{ c }; // implicit conversion of char to int
    std::cout << "implicit: " << implicit << '\n';

    // 显式转换：程序员用 static_cast 明确要求把 char 转成 int
    int explicitValue{ static_cast<int>(c) }; // explicit conversion of char to int
    std::cout << "explicit: " << explicitValue << '\n';

    return 0;
}
