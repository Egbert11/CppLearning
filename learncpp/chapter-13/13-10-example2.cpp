// ============================================================
// 来源小节：13.10 Passing and returning structs
// 示例说明：把员工打包成结构体，按 const 引用传递以避免拷贝。
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

// --- 原文示例片段（原 Example 3）---
void printEmployee(const Employee& employee) // note pass by reference here
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int main()
{
    Employee joe { 14, 32, 24.15 };
    Employee frank { 15, 28, 18.27 };

    // Print Joe's information
    printEmployee(joe);

    std::cout << '\n';

    // Print Frank's information
    printEmployee(frank);

    return 0;
}

// 预期输出：
// ID:   14
// Age:  32
// Wage: 24.15
//
// ID:   15
// Age:  28
// Wage: 18.27
