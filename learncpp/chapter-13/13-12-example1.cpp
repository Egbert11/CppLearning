// ============================================================
// 来源小节：13.12 Member selection with pointers and references
// 示例说明：用成员选择运算符 . 修改结构体对象的成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    Employee joe { 1, 34, 65000.0 };

    // --- 原文示例片段（原 Example 1）---
    // Use member selection operator (.) to select a member from struct object
    ++joe.age; // Joe had a birthday
    joe.wage = 68000.0; // Joe got a promotion

    std::cout << joe.id << ' ' << joe.age << ' ' << joe.wage << '\n';

    return 0;
}

// 预期输出：
// 1 35 68000
