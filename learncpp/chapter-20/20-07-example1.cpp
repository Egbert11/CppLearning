// 来源小节：20.7 Lambda captures
// 示例说明：无捕获的 lambda 只能使用自己参数里的东西；
//           这里直接查找固定的子串 "nut"，所以不需要捕获任何外部变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码为按原文描述重建。
// 预期输出：Found walnut

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    // A lambda can access objects with static storage duration, or constexpr
    // objects, without capturing them. Everything else needs a capture.
    auto found{ std::find_if(arr.begin(), arr.end(), [](std::string_view str) {
        return str.find("nut") != std::string_view::npos;
    }) };

    if (found == arr.end())
        std::cout << "No nuts\n";
    else
        std::cout << "Found " << *found << '\n';

    return 0;
}
