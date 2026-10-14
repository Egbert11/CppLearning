// 来源小节：7.10 Sharing global constants across multiple files (using inline variables)
// 示例说明：方式二 —— 在 constants.cpp 中用 extern constexpr 定义这些常量，赋予其外部链接。
// 原文链接：https://www.learncpp.com/cpp-tutorial/sharing-global-constants-across-multiple-files-using-inline-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 3）。

#include "constants.h"

namespace constants
{
    // 这里用 extern constexpr 使这些常量获得外部链接
    extern constexpr double pi { 3.14159 };
    extern constexpr double avogadro { 6.0221413e23 };
    extern constexpr double myGravity { 9.2 }; // m/s^2
}
