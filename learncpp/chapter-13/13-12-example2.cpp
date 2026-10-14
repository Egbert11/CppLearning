// ============================================================
// 来源小节：13.12 Member selection with pointers and references
// 示例说明：对结构体的 const 引用用 . 访问成员（引用行为像对象本身）。
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

void printEmployee(const Employee& e)
{
    // --- 原文示例片段（原 Example 2）---
    // Use member selection operator (.) to select member from reference to struct
    std::cout << "Id: " << e.id << '\n';
    std::cout << "Age: " << e.age << '\n';
    std::cout << "Wage: " << e.wage << '\n';
}

int main()
{
    Employee joe{ 1, 34, 65000.0 };

    ++joe.age;
    joe.wage = 68000.0;

    printEmployee(joe);

    return 0;
}

// 预期输出：
// Id: 1
// Age: 35
// Wage: 68000
