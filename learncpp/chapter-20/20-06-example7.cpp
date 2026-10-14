// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：auto 并不总是最好——对 C 风格字符串它推导出 const char*；
//           显式写成 std::string_view 有时更好。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建。
// 预期输出：There are 2 months with 5 letters

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
    constexpr std::array<std::string_view, 12> months{
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December" };

    // --- 原文示例片段 ---
    // Explicitly type the parameter as std::string_view
    auto found{ std::count_if(months.begin(), months.end(),
                              [](std::string_view str) {
                                  return str.length() == 5;
                              }) };
    // --- 原文示例片段结束 ---

    std::cout << "There are " << found << " months with 5 letters\n";

    return 0;
}
