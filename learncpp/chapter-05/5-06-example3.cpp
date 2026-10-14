// 来源小节：5.6 Constexpr variables
// 示例说明：完整的 constexpr 演示——合法的 constexpr 声明，以及两处会产生编译错误的声明
//           （age 不是常量表达式；five() 的返回值不是 constexpr）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-variables/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建。
// 原示例中 `constexpr int myAge { age };` 与 `constexpr int f { five() };` 是【编译错误】，
// 为让本文件可通过编译，这两行以注释保留（见下方）。取消注释即会重现编译错误。
// 预期输出（输入 30 时）：
//   Enter your age: 30
//   You entered: 30

#include <iostream>

int five()
{
    return 5;
}

int main()
{
    constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression
    constexpr int sum { 4 + 5 };      // ok: 4 + 5 is a constant expression
    constexpr int something { sum };  // ok: sum is a constant expression

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    // constexpr int myAge { age };   // compile error: age is not a constant expression  <-- 取消注释将无法编译
    // constexpr int f { five() };    // compile error: return value of five() is not constexpr  <-- 取消注释将无法编译

    std::cout << "You entered: " << age << '\n';

    (void)gravity;   // 仅为消除“未使用变量”告警
    (void)something; // 仅为消除“未使用变量”告警

    return 0;
}
