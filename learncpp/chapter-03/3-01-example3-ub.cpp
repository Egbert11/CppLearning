// 来源小节：3.1 Syntax and semantic errors
// 示例说明：运行期语义错误——整数除以 0，属于未定义行为（undefined behavior）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/
//
// 说明：本节示例为按原文描述重建。本程序可编译，但运行时除以 0 是未定义行为，
//       可能崩溃。这是被调试的对象，请勿“修复”。
//
// 预期行为：运行时除以 0 是未定义行为（可能崩溃或得到任意结果）。

#include <iostream>

int main()
{
    int a { 10 };
    int b { 0 };
    std::cout << a / b << '\n'; // division by 0 is undefined in mathematics

    return 0;
}
