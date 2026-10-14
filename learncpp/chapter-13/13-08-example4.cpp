// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：初始化列表里的值少于成员数时，未列出的成员如果有默认成员初始化器
//           就用它（wage 用 76000.0）；没有默认成员初始化器的成员则从空列表
//           拷贝初始化，也就是值初始化为 0（whatever 为 0.0）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage { 76000.0 }; // default member initializer
    double whatever;         // no default member initializer
};

int main()
{
    Employee joe { 2, 28 };

    std::cout << joe.id << ' ' << joe.age << ' ' << joe.wage << ' ' << joe.whatever << '\n';

    return 0;
}

// 预期输出：
// 2 28 76000 0
