// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：一个空初始化列表会值初始化所有成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Employee
{
    int id;
    int age;
    double wage;
};

int main()
{
    Employee joe {}; // value-initialize all members

    std::cout << joe.id << ' ' << joe.age << ' ' << joe.wage << '\n';

    return 0;
}

// 预期输出：
// 0 0 0
