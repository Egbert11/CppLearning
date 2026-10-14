// ============================================================
// 来源小节：13.11 Struct miscellany
// 示例说明：Employee 定义在全局，作为 Company 的成员；嵌套列表初始化并访问 CEO 工资。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-miscellany/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 1）---
struct Employee
{
    int id {};
    int age {};
    double wage {};
};

struct Company
{
    int numberOfEmployees {};
    Employee CEO {}; // Employee is a struct within the Company struct
};

int main()
{
    Company myCompany{ 7, { 1, 32, 55000.0 } }; // Nested initialization list to initialize Employee
    std::cout << myCompany.CEO.wage << '\n';    // print the CEO's wage

    return 0;
}

// 预期输出：
// 55000
