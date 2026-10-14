// ============================================================
// 来源小节：16.3 std::vector and the unsigned length and subscript problem
// 示例说明：符号转换在列表初始化中被禁止（编译错误），在拷贝初始化中仅可能警告。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-the-unsigned-length-and-subscript-problem/
// 预期错误：编译错误——列表初始化 `unsigned int u { s }` 是收窄（narrowing）转换，
//           依 C++ 标准为 ill-formed。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
//       GCC 15 默认把列表初始化的收窄转换降级为 -Wnarrowing 警告（不报错），
//       用 `g++ -std=c++20 -Wall -pedantic-errors 16-03-example1-error.cpp`
//       （或 Clang / MSVC）才能复现标准要求的硬错误。
//       可正常编译的版本见 16-03-example2.cpp。
// ============================================================
#include <iostream>

void foo(unsigned int)
{
}

int main()
{
    int s { 5 };

    [[maybe_unused]] unsigned int u { s }; // compile error: list initialization disallows narrowing conversion
    foo(s);                                // possible warning: copy initialization allows narrowing conversion

    return 0;
}
