// ============================================================
// 来源小节：13.7 Introduction to structs, members, and member selection
// 示例说明：用成员选择运算符（operator.）访问成员——它夹在结构体变量名和成员名
//           之间，如 joe.age。成员用起来和普通变量一样。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

int main()
{
    Employee joe {};

    joe.age = 32; // use member selection operator (.) to select the age member of variable joe

    std::cout << joe.age << '\n'; // print joe's age

    return 0;
}

// 预期输出：
// 32
