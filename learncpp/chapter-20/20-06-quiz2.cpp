// 来源小节：20.6 Introduction to lambdas (anonymous functions)（Quiz 2）
// 示例说明：用 std::sort 配合比较 averageTemperature 的 lambda，把四季按平均气温升序排列。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建（原文解答已给出完整代码）。
// 预期输出（按输出顺序）：
//   Winter
//   Spring
//   Fall
//   Summer

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int main()
{
    std::array<Season, 4> seasons{
        { { "Spring", 285.0 },
          { "Summer", 296.0 },
          { "Fall", 288.0 },
          { "Winter", 263.0 } }
    };

    // We can compare averageTemperature of the two arguments to
    // sort the array.
    std::sort(seasons.begin(), seasons.end(),
              [](const auto& a, const auto& b) {
                  return a.averageTemperature < b.averageTemperature;
              });

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }

    return 0;
}
