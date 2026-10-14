// ============================================================
// 来源小节：14.12 Delegating constructors
// 示例说明：错误地在函数体内调用 `Employee(name, id);`——它不会继续初始化 e2，
//           而是直接初始化出一个临时 Employee 并打印；e2 的 m_name 仍是默认的 "???"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/delegating-constructors/
// 备注：本节代码为按原文描述忠实重建。这是坏实践演示（能编译、能运行），请勿模仿。
//       三参构造函数只初始化了 m_isManager，成员初始化列表已结束，函数体调用为时已晚。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

// --- 原文示例片段（原 Example 5）---
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
        std::cout << "Employee " << m_name << " created\n";
    }

    Employee(std::string_view name, int id, bool isManager)
        : m_isManager { isManager } // only initializes m_isManager; m_name stays "???"
    {
        Employee(name, id); // this doesn't work as expected! (creates a temporary)
    }

    const std::string& getName() const { return m_name; }
};

int main()
{
    Employee e2{ "Dave", 42, true };
    std::cout << "e2 has name: " << e2.getName() << '\n';

    return 0;
}

// 预期输出：
// Employee Dave created
// e2 has name: ???
