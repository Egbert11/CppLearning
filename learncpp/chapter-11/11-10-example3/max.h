// 来源小节：11.10 Using function templates in multiple files
// 示例说明：把 max<T> 模板定义放进头文件 max.h，供多个源文件共享
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-function-templates-in-multiple-files/
// 本节代码为按原文描述重建

#ifndef MAX_H
#define MAX_H

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

#endif
