// ============================================================
// 来源小节：14.12 Delegating constructors
// 示例说明：Employee 的两个构造函数各自重复了相同的打印语句（构造冗余）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/delegating-constructors/
// 备注：本节代码为按原文描述忠实重建。原文作者注明：让构造函数打印通常不是好主意
//       （调试除外），因为不想打印时就没法用该构造函数。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 3）---
class Employee
{
private:
    std::string m_name { "???" };
    int m_id { 0 };
    bool m_isManager { false };

public:
    Employee(std::string_view name, int id)
        : m_name { name }, m_id { id }
    {
        std::cout << "Employee " << m_name << " created\n"; // duplicated
    }

    Employee(std::string_view name, int id, bool isManager)
        : m_name { name }, m_id { id }, m_isManager { isManager }
    {
        std::cout << "Employee " << m_name << " created\n"; // duplicated
    }
};

int main()
{
    Employee e1{ "James", 7 };
    Employee e2{ "Dave", 42, true };

    return 0;
}

// 预期输出：
// Employee James created
// Employee Dave created
