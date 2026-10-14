// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：先展示问题——std::find_if 需要一个函数指针，于是这个只用一次的函数
//           不得不命名、并放在全局作用域（因为 C++ 函数不能嵌套）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建。
// 预期输出：Found walnut

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// --- 原文示例片段 ---
// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
    // std::string_view::find returns std::string_view::npos if it doesn't find
    // the substring. Otherwise it returns the index where the substring occurs
    // in str.
    return str.find("nut") != std::string_view::npos;
}
// --- 原文示例片段结束 ---

int main()
{
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // Scan our array to see if any elements contain the "nut" substring
    auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

    if (found == arr.end())
        std::cout << "No nuts\n";
    else
        std::cout << "Found " << *found << '\n';

    return 0;
}
