// ============================================================
// 来源小节：13.9 Default member initialization
// 示例说明：空花括号时，缺省且无默认值的成员被值初始化，其余成员使用默认值。
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
    // --- 原文示例片段（原 Example 3）---
    Something s3 {}; // value initialize s3.x, use default values for s3.y and s3.z

    std::cout << "s3.x = " << s3.x << ", s3.y = " << s3.y << ", s3.z = " << s3.z << '\n';

    return 0;
}

// 预期输出：
// s3.x = 0, s3.y = 0, s3.z = 2
