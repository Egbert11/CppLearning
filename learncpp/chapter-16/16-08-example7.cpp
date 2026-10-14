// ============================================================
// 来源小节：16.8 Range-based for loops (for-each)
// 示例说明：范围 for 只能前向遍历；C++20 起可用 <ranges> 的 std::views::reverse
//           构造反向视图，实现逆序遍历。
// 原文链接：https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/
// 预期输出：
//   Dave
//   Chad
//   Bobby
//   Alex
// 备注：本节代码为按原文描述重建。需要 C++20（g++ -std=c++20）。
// ============================================================
#include <iostream>
#include <ranges> // std::views::reverse
#include <string_view>
#include <vector>

int main()
{
    std::vector<std::string_view> words { "Alex", "Bobby", "Chad", "Dave" };

    for (const auto& word : std::views::reverse(words))
        std::cout << word << '\n';

    return 0;
}
