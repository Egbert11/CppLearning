// ============================================================
// 来源小节：13.12 Member selection with pointers and references
// 示例说明：先解引用指针再选择成员 (*ptr).id，括号必不可少。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

int main()
{
    Employee joe{ 1, 34, 65000.0 };

    ++joe.age;
    joe.wage = 68000.0;

    Employee* ptr{ &joe };
    // --- 原文示例片段（原 Example 4）---
    std::cout << (*ptr).id << '\n'; // Not great but works: First dereference ptr, then use member selection

    return 0;
}

// 预期输出：
// 1
