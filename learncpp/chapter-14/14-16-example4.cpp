// ============================================================
// 来源小节：14.16 Converting constructors and the explicit keyword
// 示例说明：修复方式一——使用 std::string_view 字面量 "Joe"sv，此时只需一次
//           用户自定义转换（string_view -> Employee）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name{};

public:
    Employee(std::string_view name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
};

void printEmployee(Employee e)
{
    std::cout << e.getName();
}

int main()
{
    // --- 原文示例片段（原 Example 5）---
    using namespace std::literals;
    printEmployee( "Joe"sv); // now a std::string_view literal
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// Joe
