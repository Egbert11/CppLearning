// ============================================================
// 来源小节：13.12 Member selection with pointers and references
// 示例说明：对指针直接使用 . —— 预期编译失败。请勿修复此文件。
// 原文链接：https://www.learncpp.com/cpp-tutorial/member-selection-with-pointers-and-references/
// 预期错误：g++ 报错类似 "request for member 'id' in 'ptr',
//           which is of pointer type 'Employee*' (maybe you meant to use '->' ?)"
// 备注：本节代码为按原文描述忠实重建。此文件故意编译失败，用于演示 . 不能用于指针。
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
    // --- 原文示例片段（原 Example 3）---
    std::cout << ptr.id << '\n'; // Compile error: can't use operator. with pointers

    return 0;
}
