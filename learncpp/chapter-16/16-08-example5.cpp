// ============================================================
// 来源小节：16.8 Range-based for loops (for-each)
// 示例说明：std::string_view 通常按值传递、复制很便宜，所以对它用 auto 是合适的；
//           但若容器后来改成 std::vector<std::string>，同一个 auto 会推导为 std::string
//           并悄悄产生昂贵的复制——此时应改用 const auto&。
// 原文链接：https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/
// 预期输出：两段都打印 Alex Brad Chad Dave（每行一个）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main()
{
    // string_view 复制很便宜，auto 是合适的
    std::cout << "-- std::vector<std::string_view> with auto --\n";
    std::vector<std::string_view> words { "Alex", "Brad", "Chad", "Dave" };
    for (auto word : words)
        std::cout << word << '\n';

    // 若容器改成 std::string，auto 会隐式地复制每个字符串（性能陷阱）
    std::cout << "-- std::vector<std::string> with auto (silent expensive copy) --\n";
    std::vector<std::string> words2 { "Alex", "Brad", "Chad", "Dave" };
    for (auto word : words2) // deduces std::string, copies each element
        std::cout << word << '\n';

    // 补救：用 const auto& 保证不发生复制
    std::cout << "-- std::vector<std::string> with const auto& (fixed) --\n";
    for (const auto& word : words2)
        std::cout << word << '\n';

    return 0;
}
