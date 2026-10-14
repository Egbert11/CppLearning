// ============================================================
// 来源小节：14.2 Introduction to classes
// 示例说明：聚合初始化可以显式把 denominator 设成 0，从而构造出违反
//           类不变量的对象，随后 printFractionValue() 触发整数除以零。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-classes/
// 备注：本节代码为按原文描述忠实重建。
//       整数除以零是**未定义行为**：x86 上通常表现为运行时触发
//       SIGFPE（算术异常）而崩溃，输出依实现/平台而定。此文件可编译，
//       但运行会异常终止，请不要"修复"这一行为——它正是本示例要说明的问题。
// ============================================================
#include <iostream>

struct Fraction
{
    int numerator { 0 };
    int denominator { 1 }; // class invariant: should never be 0
};

void printFractionValue(const Fraction& f)
{
     std::cout << f.numerator / f.denominator << '\n';
}

int main()
{
    Fraction f { 5, 0 };   // create a Fraction with a zero denominator
    printFractionValue(f); // cause divide by zero error

    return 0;
}

// 预期行为：运行到 printFractionValue() 时除以零 -> 未定义行为（通常 SIGFPE 崩溃）。
