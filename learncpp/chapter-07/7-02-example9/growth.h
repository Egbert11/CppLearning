// 来源小节：7.2 User-defined namespaces and the scope resolution operator
// 示例说明：多个命名空间块——在 growth.h 中向同一个 BasicMath 命名空间追加常量 e。
//           命名空间可以在多个文件/多次声明中重复打开，所有声明加入同一个命名空间。
//           （对应原文 Example 9 的 growth.h）
// 原文链接：https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/

#ifndef GROWTH_H
#define GROWTH_H

namespace BasicMath
{
    // the constant e is also part of namespace BasicMath
    constexpr double e{ 2.7 };
}

#endif
