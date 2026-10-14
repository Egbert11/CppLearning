// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：C++20 的指定列表赋值——`joe = { .id = ..., ... }`；未被指定的
//           成员会得到其值初始化后的值。
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

    joe = { .id = joe.id, .age = 33, .wage = 66000.0 };
    std::cout << joe << '\n';

    return 0;
}

// 预期输出：
// 1 33 66000
