// ============================================================
// 来源小节：13.11 Struct miscellany
// 示例说明：把 Employee 嵌套进 Company 内部，经 Company::Employee 访问。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-miscellany/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 2）---
struct Company
{
    struct Employee // nested type
    {
        int id {};
        int age {};
        double wage {};
    };

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
