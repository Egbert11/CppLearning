// 来源小节：2.10 Introduction to the preprocessor（Example 14）
// 示例说明：宏只在其所在文件内有效：PRINT 只在 main.cpp 中定义，function.cpp 看不到它，
//           因此 function.cpp 走 #ifndef 分支，输出 "Not printing!"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-the-preprocessor/

#include <iostream>

void doSomething()
{
#ifdef PRINT
    std::cout << "Printing!\n";
#endif
#ifndef PRINT
    std::cout << "Not printing!\n";
#endif
}
