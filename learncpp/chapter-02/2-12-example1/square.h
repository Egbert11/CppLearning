// 来源小节：2.12 Header guards
// 示例说明：带 header guard 的 square.h。第一次被包含时 SQUARE_H 未定义，内容被包含并定义 SQUARE_H；
//           之后再被包含时（例如经 wave.h 间接包含），#ifndef 为假，内容被跳过，避免重复定义。
// 原文链接：https://www.learncpp.com/cpp-tutorial/header-guards/

#ifndef SQUARE_H
#define SQUARE_H

int getSquareSides() // 原文为了演示方便把函数定义写进了头文件（一般不应这样做）
{
    return 4;
}

#endif
