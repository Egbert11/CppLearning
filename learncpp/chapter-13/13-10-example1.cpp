// ============================================================
// 来源小节：13.10 Passing and returning structs
// 示例说明：把一名员工拆成三个松散变量，必须逐个成员地传递（模板方法前的坏做法）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/passing-and-returning-structs/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 2）---
void printEmployee(int id, int age, double wage)
{
    std::cout << "ID:   " << id << '\n';
    std::cout << "Age:  " << age << '\n';
    std::cout << "Wage: " << wage << '\n';
}

int main()
{
    // --- 原文示例片段（原 Example 1）---
    int id { 14 };
    int age { 32 };
    double wage { 24.15 };

    printEmployee(id, age, wage);

    return 0;
}

// 预期输出：
// ID:   14
// Age:  32
// Wage: 24.15
