// 来源小节：20.7 Lambda captures
// 示例说明：lambda 捕获不到外层的局部变量 search —— 未捕获就使用会编译失败。
//           与嵌套的普通代码块不同，lambda 不会自动看到外层局部变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 预期错误：error: 'search' is not captured
// 说明：本节代码为按原文描述重建。请勿修复，此文件故意无法编译
//       （修复方式见 20-07-example3.cpp：在捕获子句里加上 [search]）。

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
    // Won't compile: search is not captured
    auto found{ std::find_if(arr.begin(), arr.end(), [](std::string_view str) {
        return str.find(search) != std::string_view::npos;
    }) };
    // --- 原文示例片段结束 ---

    if (found == arr.end())
        std::cout << "No nuts\n";
    else
        std::cout << "Found " << *found << '\n';

    return 0;
}
