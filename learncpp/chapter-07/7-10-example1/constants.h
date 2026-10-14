// 来源小节：7.10 Sharing global constants across multiple files (using inline variables)
// 示例说明：方式一 —— 全局常量作为内部变量（C++17 之前）。头文件保护只防同一文件重复包含，
//           每个包含此头文件的 .cpp 都会得到各自的私有 constexpr 副本（内部链接）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 1）。

#ifndef CONSTANTS_H
#define CONSTANTS_H

// 定义你自己的常量命名空间
namespace constants
{
    // 实际变量是 constexpr，默认内部链接（每个 .cpp 各得一份私有副本）
    constexpr double pi { 3.14159 };
    constexpr double avogadro { 6.0221413e23 };
    constexpr double myGravity { 9.2 }; // m/s^2 —— 这颗行星上重力较轻
}

#endif
