// 来源小节：2.12 Header guards
// 示例说明：修正版 square.h —— 只放前置声明，函数定义放到 square.cpp。
//           这样即使被多个 .cpp 包含，链接期也只有一个定义（避免违反 ODR）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-guards/

#ifndef SQUARE_H
#define SQUARE_H

int getSquareSides(); // forward declaration for getSquareSides
int getSquarePerimeter(int sideLength); // forward declaration for getSquarePerimeter

#endif
