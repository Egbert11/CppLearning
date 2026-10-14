// 来源小节：7.9 Inline functions and variables
// 示例说明：pi.h —— 用 include guard 并内联定义 pi()，供各翻译单元包含。
// 原文链接：https://www.learncpp.com/cpp-tutorial/inline-functions-and-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 5）。

#ifndef PI_H
#define PI_H

inline double pi() { return 3.14159; }

#endif
