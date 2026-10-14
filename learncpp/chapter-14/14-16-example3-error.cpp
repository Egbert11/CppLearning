// ============================================================
// 来源小节：14.16 Converting constructors and the explicit keyword
// 示例说明：需要两次用户自定义转换，故编译失败——"Joe"（const char*）要先转成
//           std::string_view，再转成 Employee，而只允许一次用户自定义转换。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
// 备注：本节代码为按原文描述忠实重建。
//
// *** 本文件为预期编译失败示例（-error），请勿"修复" ***
// 预期错误：printEmployee("Joe"); 处——需要两次用户自定义转换
//           （no matching function / conversion from 'const char [4]' to 'Employee'）。
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

void printEmployee(Employee e) // has an Employee parameter
{
    std::cout << e.getName();
}

int main()
{
    printEmployee("Joe"); // error: requires two user-defined conversions

    return 0;
}
