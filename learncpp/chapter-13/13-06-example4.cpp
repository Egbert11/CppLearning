// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：同一个有作用域枚举内部的枚举量彼此类型相同，可以比较。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

enum class Color
{
    red,
    blue,
};

int main()
{
    Color shirt { Color::red };

    if (shirt == Color::red) // this Color to Color comparison is okay
        std::cout << "The shirt is red!\n";
    else if (shirt == Color::blue)
        std::cout << "The shirt is blue!\n";

    return 0;
}

// 预期输出：
// The shirt is red!
