// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：聚合体也可以用初始化列表做成员逐一赋值。用 `joe = { ... }` 时，
//           不需要改动的成员也要用占位值填上。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

std::ostream& operator<<(std::ostream& out, const Employee& e)
{
    out << e.id << ' ' << e.age << ' ' << e.wage;
    return out;
}

int main()
{
    Employee joe { 1, 32, 60000.0 };

    // Joe had a birthday and got a raise
    // 逐个成员赋值：
    joe.age  = 33;
    joe.wage = 66000.0;
    std::cout << joe << '\n';

    // 或通过初始化列表做成员逐一赋值（id 保持不变，故用 joe.id 占位）：
    joe = { joe.id, 33, 66000.0 };
    std::cout << joe << '\n';

    return 0;
}

// 预期输出：
// 1 33 66000
// 1 33 66000
