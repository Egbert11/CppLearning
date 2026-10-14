// 来源小节：20.6 Introduction to lambdas (anonymous functions)
// 示例说明：泛型 lambda（C++14 起可用 auto 作形参，编译器从调用处推断类型）。
//           用 std::adjacent_find 找出相邻两个月首字母相同的月份。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建。
// 预期输出：June and July start with the same letter

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
    // --- 原文示例片段 ---
    constexpr std::array<std::string_view, 12> months{ // Used to size month names
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December" };

    // See if the first letter of the first month matches the first letter of the next month
    auto found{ std::adjacent_find(months.begin(), months.end(),
                                   [](const auto& a, const auto& b) {
                                       return (a[0] == b[0]);
                                   }) };

    if (found == months.end())
        std::cout << "No months begin with the same letter\n";
    else
        std::cout << *found << " and " << *(found + 1) << " start with the same letter\n";
    // --- 原文示例片段结束 ---

    return 0;
}
