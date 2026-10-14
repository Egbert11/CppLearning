// ============================================================
// 来源小节：5.1 Constant variables (named constants)
// 示例说明：对象式宏忽略 C++ 作用域。原文在一个函数内 #define gravity 9.8，
//           结果预处理器把文件中后续出现的所有 gravity 都替换成 9.8，
//           连后面函数的形参名 gravity 也被替换，导致编译错误。
//           为保持可编译，原始会出错的宏写法以注释保留，改用常量变量正确实现。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/
// ============================================================
#include <iostream>

// --- 原文示例片段（会编译失败）---
// void someFcn()
// {
// #define gravity 9.8   // 宏定义在此，但它会替换整个文件后续所有的 gravity
// }
//
// void printGravity(double gravity) // 编译错误：形参名被宏替换成了 9.8
// {
//     std::cout << gravity << '\n';
// }
// --- 原文示例片段结束 ---

// 正确做法：用常量变量代替宏，作用域正常，不会污染其他代码。
constexpr double gravity { 9.8 };

void printGravity(double gravity)
{
    std::cout << gravity << '\n';
}

int main()
{
    printGravity(gravity);

    return 0;
}
