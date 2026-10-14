// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：struct 的公有成员——name 与 firstInitial 是两个互相依赖的数据，
//           但用户可单独改写 name 而忘记同步 firstInitial，从而破坏不变式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
// --- 原文示例片段（原 Example 2）---
struct Employee
{
    std::string name { "John" };
    char firstInitial { 'J' }; // must match the first character of the name

    void print() const
    {
        std::cout << name << " has first initial " << firstInitial << '\n';
    }
};

int main()
{
    Employee e{};
    e.print();

    e.name = "Mark"; // firstInitial is now out of sync (still 'J')
    e.print();

    return 0;
}

// 预期输出：
// John has first initial J
// Mark has first initial J
