// 来源小节：7.10 Sharing global constants across multiple files (using inline variables)
// 示例说明：方式三 —— 全局常量作为内联变量（C++17）。inline constexpr 使常量默认外部链接，
//           可被任意多个文件包含而只实例化一次。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 6）。

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    // note: now inline constexpr
    inline constexpr double pi { 3.14159 };
    inline constexpr double avogadro { 6.0221413e23 };
    inline constexpr double myGravity { 9.2 }; // m/s^2
}

#endif
