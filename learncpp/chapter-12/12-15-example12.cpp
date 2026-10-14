// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：上例的指针版本，可读性与可维护性并不逊色于 reference_wrapper
//           版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 备注：本节代码为按原文描述忠实重建（原 Example 12）。
// ============================================================
#include <iostream>
#include <string>

struct Employee
{
    std::string name{};
    int id{};
};

void printEmployeeID(const Employee* e=nullptr)
{
    if (e)
        std::cout << "The employee's ID is: " << e->id << '\n';
    else
        std::cout << "The employee's ID is unknown.\n";
}

int main()
{
    printEmployeeID();

    Employee e{ "Dave", 62 };
    printEmployeeID(&e);

    return 0;
}
