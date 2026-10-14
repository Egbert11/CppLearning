// 来源小节：10.7 Typedefs and type aliases
// 示例说明：把类型别名放进头文件，用头文件保护包裹，供多个 .cpp 文件共享。
//           （对应原文示例 6 的 mytypes.h）
// 原文链接：https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
//
// 本节代码为按原文描述重建。

#ifndef MYTYPES_H
#define MYTYPES_H

using Miles = long;
using Speed = long;

#endif
