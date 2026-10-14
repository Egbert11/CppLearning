// ============================================================
// 来源小节：14.3 Member functions
// 示例说明：非成员函数必须先声明后使用——x() 在 y() 尚未声明时就调用它，
//           产生编译错误（编译器还不知道 y 是什么）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-functions/
// 备注：本节代码为按原文描述忠实重建。**预期编译失败**，文件中保留原始顺序，
//       请勿"修复"——它正是本示例要演示的顺序依赖问题。
//       预期错误（g++）：'y' was not declared in this scope
// ============================================================
#include <iostream>

int x()
{
    return y(); // compile error: the compiler doesn't know what y is yet
}

int y()
{
    return 5;
}

int main()
{
    std::cout << x();
    return 0;
}
