// ============================================================
// 来源小节：16.8 Range-based for loops (for-each) —— 测验 2 解答
// 示例说明：写一个函数模板 isValueInArray()，接受 const std::vector<T>& 与 const T&，
//           用范围 for 查找并返回是否找到；main 中显式指定模板实参 std::string_view，
//           使 std::string 输入能隐式转换后参与比较。
// 原文链接：https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/
// 备注：本节代码为按原文描述重建。交互式程序，需要 stdin 输入。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& value)
{
    // 用 const auto& 遍历，避免复制
    for (const auto& a : arr)
    {
        if (a == value)
            return true;
    }

    return false;
}

int main()
{
    std::vector<std::string_view> names { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    std::cout << "Enter a name: ";
    std::string username {};
    std::cin >> username;

    // 必须显式指定模板实参为 std::string_view：否则 T 会被推导为 std::string，
    // 而 std::vector<std::string_view> 无法与 std::string 比较。
    // 另一种写法是让模板自行推导，再把 username 用 static_cast<std::string_view>(username) 传入。
    if (isValueInArray<std::string_view>(names, username))
        std::cout << username << " was found.\n";
    else
        std::cout << username << " was not found.\n";

    return 0;
}
