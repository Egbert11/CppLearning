// 来源小节：11.4 Deleting functions
// 示例说明：进阶技巧——删除一个兜底的函数模板来强制精确类型匹配：int 走非模板重载，
//           其余类型由已删除的模板接住，从而在编译期被拒绝。
// 原文链接：https://www.learncpp.com/cpp-tutorial/deleting-functions/
//
// 编译：g++ -std=c++20 -Wall 11-04-example3-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：printInt('a') 与 printInt(true) 匹配到已删除的模板，报 "use of deleted function"。
//
// 本节代码为按原文描述重建。

#include <iostream>

// This function will take precedence for arguments of type int
void printInt(int x)
{
    std::cout << x << '\n';
}

// This function template will take precedence for arguments of other types
// Since this function template is deleted, calls to it will halt compilation
template <typename T>
void printInt(T x) = delete;

int main()
{
    printInt(97);   // okay
    printInt('a');  // compile error
    printInt(true); // compile error

    return 0;
}
