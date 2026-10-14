// ============================================================
// 来源小节：14.9 Introduction to constructors
// 示例说明：struct 是聚合体，可用花括号列表直接做聚合初始化，成员按声明顺序初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-constructors/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 1）---
struct Foo
{
    int x {};
    int y {};
};

int main()
{
    Foo foo { 6, 7 }; // uses aggregate initialization

    std::cout << foo.x << ' ' << foo.y << '\n';

    return 0;
}

// 预期输出：
// 6 7
