// ============================================================
// 来源小节：13.9 Default member initialization
// 示例说明：显式初始化列表为每个成员提供值，此时不使用任何默认值。
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
    // --- 原文示例片段（原 Example 2）---
    Something s2 { 5, 6, 7 }; // use explicit initializers for s2.x, s2.y, and s2.z (no default values are used)

    std::cout << "s2.x = " << s2.x << ", s2.y = " << s2.y << ", s2.z = " << s2.z << '\n';

    return 0;
}

// 预期输出：
// s2.x = 5, s2.y = 6, s2.z = 7
