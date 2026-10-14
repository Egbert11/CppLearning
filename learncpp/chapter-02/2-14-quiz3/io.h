// 来源小节：2.x Chapter 2 summary and quiz（官方编号 2.x）
// 题目 3：把前置声明改成用头文件 io.h 提供，并要求该头文件带有 header guard。
// 示例说明：io.h —— 包含两个函数原型，并用 IO_H 作为 header guard。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-2-summary-and-quiz/

#ifndef IO_H
#define IO_H

int readNumber();
void writeAnswer(int x);

#endif
