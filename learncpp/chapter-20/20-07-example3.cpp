// 来源小节：20.7 Lambda captures
// 示例说明：在捕获子句里写 [search]，按值捕获外层变量 search。
//           Key insight：捕获的是外层变量的**副本**，而不是变量本身。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// 交互运行示例：
//   search for: nana
//   Found banana

#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>

int main()
{
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    // --- 原文示例片段 ---
    // Capture @search by value
    auto found{ std::find_if(arr.begin(), arr.end(), [search](std::string_view str) {
        return str.find(search) != std::string_view::npos;
    }) };
    // --- 原文示例片段结束 ---

    if (found == arr.end())
        std::cout << "No nuts\n";
    else
        std::cout << "Found " << *found << '\n';

    return 0;
}
