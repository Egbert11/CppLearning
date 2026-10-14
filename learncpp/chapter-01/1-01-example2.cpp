// 来源小节：1.1 Statements and the structure of a program
// 示例说明：故意省略输出语句末尾的分号，用于演示"语法错误（syntax error）"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/statements-and-the-structure-of-a-program/
//
// ※※※ 注意 ※※※
// 本文件【故意无法编译】，它存在的唯一目的就是演示编译器如何报告语法错误。
// 请不要尝试编译它；若整套示例一起编译，请单独排除本文件。
//
// 预期编译错误（原文给出的示例）：
//   Clang:          prog.cc:5:31: error: expected ';' after expression
//   Visual Studio:  c:\vcprojects\hello.cpp(6): error C2143: syntax error : missing ';' before 'return'
//
// 要点：编译器有时会在"该修的那一行的下一行"报错。若报错行看起来没问题，就检查它的前一行。

#include <iostream>

int main()
{
   std::cout << "Hello world!"
   return 0;
}
