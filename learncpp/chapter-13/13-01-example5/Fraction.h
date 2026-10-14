// ============================================================
// 来源小节：13.1 Introduction to program-defined (user-defined) types
// 文件说明：把 Fraction 类型定义放进头文件，供多个代码文件共享。
//           注意这是一份完整定义，不是前置声明——因为编译器必须知道
//           要分配多少内存。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#ifndef FRACTION_H
#define FRACTION_H

// Define a new type named Fraction
// This only defines what a Fraction looks like, it doesn't create one
// Note that this is a full definition, not a forward declaration
struct Fraction
{
    int numerator {};
    int denominator {};
};

#endif
