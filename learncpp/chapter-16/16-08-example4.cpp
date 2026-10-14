// ============================================================
// 来源小节：16.8 Range-based for loops (for-each)
// 示例说明：遍历 std::vector<std::string>：用 auto 会把每个 std::string 复制一份
//           （昂贵）；改用 const auto& 让 word 绑定为常量引用即可避免复制。
// 原文链接：https://www.learncpp.com/cpp-tutorial/range-based-for-loops-for-each/
// 预期输出：
//   Alex
//   Brad
//   Chad
//   Dave
//   （第二段 const auto& 输出相同）
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> words { "Alex", "Brad", "Chad", "Dave" };

    // auto 推导为 std::string，每轮复制一个字符串——代价高
    std::cout << "-- auto (copies each std::string) --\n";
    for (auto word : words)
        std::cout << word << '\n';

    // const auto& 让 word 成为对元素的常量引用，不发生复制
    std::cout << "-- const auto& (no copy) --\n";
    for (const auto& word : words)
        std::cout << word << '\n';

    return 0;
}
