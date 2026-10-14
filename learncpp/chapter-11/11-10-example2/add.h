// 来源小节：11.10 Using function templates in multiple files
// 示例说明：把函数模板定义放进头文件 add.h。模板定义被豁免于 ODR 的"每程序一个定义"，
//           任何需要它的源文件 #include 该头文件，编译器就能看到完整定义并按需实例化。
//           由函数模板隐式实例化出的函数是隐式 inline 的，因此可出现在多个文件中。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/
// 本节代码为按原文描述重建

#ifndef ADD_H
#define ADD_H

template <typename T>
T addOne(T x) // function template definition
{
    return x + 1;
}

#endif
