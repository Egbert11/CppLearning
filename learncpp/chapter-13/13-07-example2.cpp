// ============================================================
// 来源小节：13.7 Introduction to structs, members, and member selection
// 示例说明：用 struct 把多个变量打成一个类型。类型定义只描述外形、不创建
//           对象；用该类型定义变量（对象）时才真正创建，空花括号 {} 会做值
//           初始化。同一个 struct 类型可以定义多个对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    Employee joe {};   // Employee is the type, joe is the variable name
    Employee frank {}; // create an Employee struct for Frank

    (void)joe;
    (void)frank;
    return 0;
}
