// 来源小节：3.1 Syntax and semantic errors
// 示例说明：运行期语义错误——使用未初始化的变量，结果未定义（undefined result）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/
//
// 说明：本节示例为按原文描述重建。本程序可编译，但读取未初始化变量是未定义行为，
//       输出不确定。这是被调试的对象，请勿“修复”。
//
// 预期行为：x 未初始化，读取它得到未定义的结果（不同编译器/运行可能不同）。

#include <iostream>

int main()
{
    int x; // uninitialized variable
    std::cout << x << '\n'; // using the value of uninitialized x leads to an undefined result

    return 0;
}
