// 来源小节：7.10 Sharing global constants across multiple files (using inline variables)
// 示例说明：方式二 —— 全局常量作为外部变量。头文件里只放前向声明。
//           注意：前向声明不能是 constexpr，必须写成 extern const，且要放在命名空间内。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 4）。

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    // 因为真实变量位于命名空间中，前向声明也必须放在命名空间里
    // 前向声明不能是 constexpr，所以这里写 extern const
    extern const double pi;
    extern const double avogadro;
    extern const double myGravity;
}

#endif
