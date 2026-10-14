// ============================================================
// 来源小节：13.6 Scoped enumerations (enum classes)
// 示例说明：无作用域枚举不是类型安全的——比较两个不同的枚举类型时，编译器会
//           退化成把它们都转成 int 再比较。Color::red 与 Fruit::banana 都是
//           值 0，于是"相等"成立，这在语义上是错的。
// 原文链接：https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/
// 备注：本节代码为按原文描述忠实重建。GCC -Wall 会对跨枚举比较发出
//       -Wenum-compare 警告（见文件名 -warning）。
// ============================================================
#include <iostream>

enum Color
{
    red,
    blue,
};

enum Fruit
{
    banana,
    apple,
};

int main()
{
    Color color{ red };
    Fruit fruit{ banana };

    if (color == fruit) // The compiler will compare color and fruit as integers
        std::cout << "color and fruit are equal\n"; // and find they are equal!
    else
        std::cout << "color and fruit are not equal\n";

    return 0;
}

// 预期输出：
// color and fruit are equal
