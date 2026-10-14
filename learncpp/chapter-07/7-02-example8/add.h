// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：跨头文件/源文件的命名空间前向声明——add.h 在 namespace BasicMath 内声明 add，
//           add.cpp 在其中定义，main.cpp 用限定名 BasicMath::add 调用。（对应原文 Example 8）
//           多文件示例，编译：g++ -std=c++20 -Wall 7-02-example8/*.cpp
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
//
// 预期输出：7
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#ifndef ADD_H
#define ADD_H

namespace BasicMath
{
    // function add() is part of namespace BasicMath
    int add(int x, int y);
}

#endif
