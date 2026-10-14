// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：对可选参数而言，函数重载常常是更优解：一个重载不带参数、一个
//           带值，既避免空值处理，也能接受右值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 备注：本节代码为按原文描述忠实重建（原 Example 13）。
// ============================================================
#include <iostream>
#include <string>

struct Employee
{
    std::string name{};
    int id{};
};

void printEmployeeID()
{
    std::cout << "The employee's name and ID is unknown.\n";
}

void printEmployeeID(const Employee& e)
{
    std::cout << "The employee's name is " << e.name << " and ID is " << e.id << '\n';
}

int main()
{
    printEmployeeID();

    Employee e{ "Dave", 62 };
    printEmployeeID(e);

    printEmployeeID( { "Dave", 62 } ); // can also pass an rvalue

    return 0;
}
