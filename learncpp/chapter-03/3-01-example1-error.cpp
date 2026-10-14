// 来源小节：3.1 Syntax and semantic errors
// 示例说明：演示一个包含多处“语法错误”的程序。
//           该程序含原文故意保留的错误，**故意无法编译**（这正是被演示的对象，请勿“修复”）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/syntax-and-semantic-errors/
//
// 说明：本节示例为按原文描述重建。
//
// 编译器应当报告的错误（至少）：
//   - int main( 缺少右括号 ) 与左花括号 {
//   - 变量名 1x 不能以数字开头
//   - std::cout 语句多处语法错误（多余分号、不存在的 operator+++、缺少分号、x 未声明）
//   - return 0 语句末尾缺少分号

#include <iostream>

int main( // missing closing parenthesis ) and brace {
{
    int 1x; // variable name can't start with a number
    std::cout << 1x+++; // extraneous semicolon; operator+++ does not exist;
                        // missing semicolon at end of statement; x is undeclared

    return 0 // missing semicolon at end of statement
}
