// ============================================================
// 来源小节：16.8 Range-based for loops (for-each) —— 测验 1 解答
// 示例说明：读入一个名字，在 8 个名字的列表中用范围 for 查找，
//           用 bool 标记是否找到，并输出结果。
// 原文链接：https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/
// 备注：本节代码为按原文描述重建。交互式程序，需要 stdin 输入。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main()
{
    std::vector<std::string_view> names { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    std::cout << "Enter a name: ";
    std::string username {};
    std::cin >> username;

    // 用 bool 记录名字是否找到
    bool found { false };
    for (std::string_view name : names)
    {
        if (name == username)
        {
            found = true;
            break;
        }
    }

    if (found)
        std::cout << username << " was found.\n";
    else
        std::cout << username << " was not found.\n";

    return 0;
}
