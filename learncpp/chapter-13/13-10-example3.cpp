// ============================================================
// 来源小节：13.10 Passing and returning structs
// 示例说明：直接传递临时（无名）结构体；显式写类型无歧义，裸花括号依赖隐式转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-structs/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

void printEmployee(const Employee& employee)
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int main()
{
    // --- 原文示例片段（原 Example 4）---
    printEmployee(Employee { 14, 32, 24.15 }); // Employee is explicitly specified (and the preferred form)
    printEmployee({ 15, 28, 18.27 });          // The type is explicitly specified in the function declaration, so the compiler can deduce the type here

    return 0;
}

// 预期输出：
// ID:   14
// Age:  32
// Wage: 24.15
// ID:   15
// Age:  28
// Wage: 18.27
