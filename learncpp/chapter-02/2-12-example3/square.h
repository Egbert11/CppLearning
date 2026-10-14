// 来源小节：2.12 Header guards
// 示例说明：#pragma once 版本的 square.h —— 由编译器负责去重，效果等同传统 header guard。
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-guards/

#pragma once

int getSquareSides(); // forward declaration for getSquareSides
int getSquarePerimeter(int sideLength); // forward declaration for getSquarePerimeter
