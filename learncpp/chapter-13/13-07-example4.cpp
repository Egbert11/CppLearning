// ============================================================
// 来源小节：13.7 Introduction to structs, members, and member selection
// 示例说明：两个员工对象，演示成员的赋值、算术、比较，以及对成员做自增。
//           结构体的好处：每个对象只需一个新名字，成员名由类型固定，因此
//           多个同类型对象拥有一致的成员名，代码更整齐、组织性更好。
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
    joe.id = 14;
    joe.age = 32;
    joe.wage = 60000.0;

    Employee frank {};
    frank.id = 15;
    frank.age = 28;
    frank.wage = 45000.0;

    int totalAge { joe.age + frank.age };
    std::cout << "Joe and Frank have lived " << totalAge << " total years\n";

    if (joe.wage > frank.wage)
        std::cout << "Joe makes more than Frank\n";
    else if (joe.wage < frank.wage)
        std::cout << "Joe makes less than Frank\n";
    else
        std::cout << "Joe and Frank make the same amount\n";

    // Frank got a promotion
    frank.wage += 5000.0;

    // Today is Joe's birthday
    ++joe.age; // use pre-increment to increment Joe's age by 1

    return 0;
}

// 预期输出：
// Joe and Frank have lived 60 total years
// Joe makes more than Frank
