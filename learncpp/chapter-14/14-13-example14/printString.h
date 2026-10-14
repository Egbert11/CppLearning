// ============================================================
// 来源小节：14.13 Temporary class objects
// 文件说明：printString 的头文件——接受 const std::string& 参数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#ifndef PRINT_STRING_H
#define PRINT_STRING_H

#include <iostream>
#include <string>

void printString(const std::string& s)
{
    std::cout << s;
}

#endif
