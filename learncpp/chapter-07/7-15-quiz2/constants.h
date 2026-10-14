// 来源小节：7.x Chapter 7 summary and quiz（测验第 2 题）
// 示例说明：constants.h —— 提供 Constants::maxClassSize == 35。
//           在支持 C++17 的编译器上使用 inline constexpr，使该常量可安全地放在头文件中。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-7-summary-and-quiz/
//
// 本节示例为按原文描述重建（对应原文 Quiz Question #2 的解答）。

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants
{
    // 若编译器不支持 C++17，请去掉 inline 关键字，改为普通 constexpr
    inline constexpr int maxClassSize{ 35 };
}

#endif
