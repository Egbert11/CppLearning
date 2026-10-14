// ============================================================
// 来源小节：14.12 Delegating constructors
// 示例说明：委托构造函数——Employee(name) 在成员初始化列表中委托给
//           Employee(name, 0)，由后者完成真正的成员初始化与打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/delegating-constructors/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 6）---
class Employee
{
private:
    std::string m_name { "???" };
    int m_id { 0 };

public:
    Employee(std::string_view name)
        : Employee{ name, 0 } // delegate to Employee(std::string_view, int)
    {
    }

    Employee(std::string_view name, int id)
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
