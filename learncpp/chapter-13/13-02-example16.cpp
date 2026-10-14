// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：用相等运算符 == 和 != 判断枚举变量当前持有哪个枚举量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

enum Color
{
    black,
    red,
    blue,
    green,
};

int main()
{
    Color shirt { blue };

    if (shirt == blue)
        std::cout << "Your shirt is blue!\n";
    else
        std::cout << "Your shirt is not blue!\n";

    return 0;
}

// 预期输出：
// Your shirt is blue!
