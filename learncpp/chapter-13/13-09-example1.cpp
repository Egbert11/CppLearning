// ============================================================
// 来源小节：13.9 Default member initialization
// 示例说明：无初始化列表时，无默认值的成员保持未初始化，其余成员使用默认值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-member-initialization/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Something
{
    int x;       // no default initialization value (bad)
    int y {};    // value-initialized by default
    int z { 2 }; // explicit default value
};

int main()
{
    // --- 原文示例片段（原 Example 1）---
    Something s1; // s1.x is uninitialized, s1.y is 0, and s1.z is 2

    // s1.x 未初始化，读取它是未定义行为，这里只看被正确初始化的成员：
    std::cout << "s1.y = " << s1.y << ", s1.z = " << s1.z << '\n';

    return 0;
}

// 预期输出：
// s1.y = 0, s1.z = 2
