// ============================================================
// 来源小节：13.1 Introduction to program-defined (user-defined) types
// 文件说明：包含 Fraction.h 后即可使用 Fraction 类型。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-program-defined-user-defined-types/
// 构建：g++ -std=c++20 -Wall 13-01-example5/*.cpp
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include "Fraction.h" // include our Fraction definition in this code file

// Now we can make use of our Fraction type
int main()
{
    Fraction f{ 3, 4 }; // this actually creates a Fraction object named f

    (void)f; // 原文未使用 f，这里仅为消除 -Wunused-variable 警告
    return 0;
}
