// ============================================================
// 来源小节：13.12 Member selection with pointers and references
// 示例说明：用箭头运算符 ptr->id（等价于 (*ptr).id，且更干净）。
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
    // --- 原文示例片段（原 Example 5）---
    std::cout << ptr->id << '\n'; // Better: use -> to select member from pointer to object

    return 0;
}

// 预期输出：
// 1
