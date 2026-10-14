// ============================================================
// 来源小节：12.15 std::optional
// 示例说明：（进阶）当 T 复制代价高昂（如含 std::string 的 Employee）时，
//           std::optional<T> 的参数会带来复制开销，因为 C++23 前
//           std::optional 不支持引用。可用 std::reference_wrapper 在
//           optional 内部模拟引用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdoptional/
// 备注：本节代码为按原文描述忠实重建（原 Example 11）。
// ============================================================
#include <functional> // for std::reference_wrapper
#include <iostream>
#include <optional>
#include <string>

struct Employee
{
    std::string name{};
    int id{};
};

void printEmployeeID(std::optional<std::reference_wrapper<Employee>> e = std::nullopt)
{
    if (e)
        std::cout << "The employee's ID is: " << e->get().id << '\n';
    else
        std::cout << "The employee's ID is unknown.\n";
}

int main()
{
    printEmployeeID();

    Employee e{ "Dave", 62 };
    printEmployeeID(e);

    return 0;
}
