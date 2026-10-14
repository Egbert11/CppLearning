// ============================================================
// 来源小节：17.1 Introduction to std::array
// 示例说明：std::array 的长度不能是运行时才能确定的值——非 const 变量与
//           "运行期常量"（函数形参 const int）都不算常量表达式，编译器会报错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-stdarray/
// 预期错误：编译错误——'length' is not a constant expression；
//           'numStudents' is not a constant expression。
// 备注：本文件为预期编译失败示例（-error），请勿修复。
// ============================================================
#include <array>
#include <iostream>

void foo(const int length) // length is a runtime constant
{
    std::array<int, length> e {}; // error: length is not a constant expression
}

int main()
{
    int numStudents{};
    std::cin >> numStudents;
    std::array<int, numStudents> {}; // error: numStudents is not a constant expression

    return 0;
}
