// ============================================================
// 来源小节：5.5 Constant expressions
// 示例说明：课后测验 a–h。判断每个初始化式是否为常量表达式、
//           以及每个变量是否可用于常量表达式。各题按原文相互独立
//           （依赖项以注释标明），故分别放在独立作用域中以便编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-expressions/
// ============================================================
#include <iostream>

// getNumber returns an int by value
int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y;
    return y;
}

int main()
{
    // (a) 初始化式是常量，变量不是（a 是 char 非 const）——char a { 'q' };
    { [[maybe_unused]] char a { 'q' }; }

    // (b) 初始化式是常量，变量可用于常量表达式——const int b { 0 };
    { [[maybe_unused]] const int b { 0 }; }

    // (c) 初始化式是常量，变量不是（double 非整型）——const double c { 5.0 };
    { [[maybe_unused]] const double c { 5.0 }; }

    // (d) a defined as: char a { 'q' };  -> 两者都不是常量
    { [[maybe_unused]] char a { 'q' };
      [[maybe_unused]] const int d { a * 2 }; }

    // (e) c defined as: const double c { 5.0 };  -> 两者都不是常量
    { [[maybe_unused]] const double c { 5.0 };
      [[maybe_unused]] int e { c + 1.0 }; }

    // (f) d defined as: const int d { 0 };  -> 两者都是常量
    { [[maybe_unused]] const int d { 0 };
      [[maybe_unused]] const int f { d * 2 }; }

    // (g) 两者都不是常量（getNumber 不是 constexpr）
    { [[maybe_unused]] const int g { getNumber() }; }

    // (h) 额外题：值初始化为 0，两者都是常量
    { [[maybe_unused]] const int h{}; }

    return 0;
}
