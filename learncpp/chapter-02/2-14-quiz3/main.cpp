// 来源小节：2.x Chapter 2 summary and quiz（官方编号 2.x）
// 题目 3：把前置声明改成用头文件 io.h 提供。
// 示例说明：main.cpp 只需 #include "io.h"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/
//
// 编译：g++ -std=c++20 -Wall 2-14-quiz3/main.cpp 2-14-quiz3/io.cpp -o quiz3

#include "io.h"

int main()
{
    int x { readNumber() };
    int y { readNumber() };

    writeAnswer(x + y);

    return 0;
}
