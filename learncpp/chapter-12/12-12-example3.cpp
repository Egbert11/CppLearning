// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：返回对 static 局部变量的 const 引用是安全的：它具有静态存储期，
//           在函数返回后仍然存在。此为“学术性”演示。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// 预期输出：This program is named Calculator
// 备注：本节代码为按原文描述忠实重建（原 Example 1、2 是纯声明；本文件对应原 Example 3）。
// ============================================================
#include <iostream>
#include <string>

const std::string& getProgramName() // returns a const reference
{
    static const std::string s_programName { "Calculator" }; // has static duration, destroyed at end of program

    return s_programName;
}

int main()
{
    std::cout << "This program is named " << getProgramName() << '\n';

    return 0;
}
