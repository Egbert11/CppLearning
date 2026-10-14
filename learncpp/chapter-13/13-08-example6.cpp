// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：为 struct 重载 operator<< 是常见便利做法（格式由你决定）。这里
//           给出最简形式：用空格分隔成员。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。joe.wage 未被指定，值初始化为 0。
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
    Employee joe { 2, 28 }; // joe.wage will be value-initialized to 0.0
    std::cout << joe << '\n';

    return 0;
}

// 预期输出：
// 2 28 0
