// ============================================================
// 来源小节：14.12 Delegating constructors
// 示例说明：用 static constexpr 具名常量 default_id 统一初始值——
//           它同时用作 m_id 的默认成员初始化器和 id 形参的默认实参。
// 原文链接：https://www.learncpp.com/cpp-tutorial/delegating-constructors/
// 备注：本节代码为按原文描述忠实重建。static 表示所有对象共享一份常量，
//       而不是每个对象各存一份。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 8）---
class Employee
{
private:
    static constexpr int default_id { 0 }; // one shared constant

    std::string m_name {};
    int m_id { default_id };

public:
    Employee(std::string_view name, int id = default_id)
        : m_name { name }, m_id { id }
    {
        std::cout << "Employee " << m_name << " created\n";
    }
};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };

    return 0;
}

// 预期输出：
// Employee James created
// Employee Dave created
