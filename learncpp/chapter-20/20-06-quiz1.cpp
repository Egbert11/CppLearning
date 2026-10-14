// 来源小节：20.6 Introduction to lambdas (anonymous functions)（Quiz 1）
// 示例说明：用 std::max_element 配合一个比较 points 的 lambda 找出得分最高的学生。
//           提示：返回的是迭代器，需要解引用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-lambdas-anonymous-functions/
// 说明：本节代码为按原文描述重建（原文解答已给出完整代码）。
// 预期输出：Dan is the best student

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Student
{
    std::string_view name{};
    int points{};
};

int main()
{
    constexpr std::array<Student, 8> arr{
        { { "Albert", 3 },
          { "Ben", 5 },
          { "Christine", 2 },
          { "Dan", 8 }, // Dan has the most points (8).
          { "Enchilada", 4 },
          { "Francis", 1 },
          { "Greg", 3 },
          { "Hagrid", 5 } }
    };

    const auto best{ // returns an iterator
        std::max_element(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            return a.points < b.points;
        })
    };

    std::cout << best->name << " is the best student\n"; // must dereference iterator to get element

    return 0;
}
