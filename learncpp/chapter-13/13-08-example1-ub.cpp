// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：和普通变量一样，数据成员不会自动初始化。未初始化就读它们（这里读
//           joe.id）是未定义行为。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。本文件演示未定义行为，能编译但结果
//       依实现而定（可能读到垃圾值）；-Wall 会给出 -Wuninitialized 警告，
//       这正是本示例要表达的问题。
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
    Employee joe; // note: no initializer
    std::cout << joe.id; // undefined behavior: joe.id, joe.age, joe.wage are uninitialized

    return 0;
}

// 预期：编译通过，但运行结果不确定（读取未初始化内存）。
