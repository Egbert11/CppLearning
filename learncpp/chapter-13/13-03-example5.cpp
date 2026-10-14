// ============================================================
// 来源小节：13.3 Unscoped enumerator integral conversions
// 示例说明：无作用域枚举可以作为整体隐式转换为整数值。因为没有针对 Color 的
//           operator<<，编译器会把 shirt 转成整数再打印，所以输出 2 而不是 blue。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

enum Color
{
    black,   // assigned 0
    red,     // assigned 1
    blue,    // assigned 2
    green,   // assigned 3
    white,   // assigned 4
    cyan,    // assigned 5
    yellow,  // assigned 6
    magenta, // assigned 7
};

int main()
{
    Color shirt{ blue };

    std::cout << "Your shirt is " << shirt << '\n'; // what does this do?

    return 0;
}

// 预期输出：
// Your shirt is 2
