// ============================================================
// 来源小节：16.11 std::vector and stack behavior
// 示例说明：用栈操作解决"数量未知的成绩"问题——用户输入 -1 结束，
//           无需预先计数或维护长度，vector 负责存储并自动增长。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdvector-and-stack-behavior/
// 预期输出（交互式，示例会话）：
//   Enter a score (or -1 to finish): 5
//   Enter a score (or -1 to finish): 3
//   Enter a score (or -1 to finish): -1
//   Your list of scores:
//   5 3
// 备注：本节代码为按原文描述重建。交互式程序，需要 stdin 输入。
// ============================================================
#include <iostream>
#include <limits>
#include <vector>

int main()
{
    std::vector<int> scoreList {};

    while (true)
    {
        std::cout << "Enter a score (or -1 to finish): ";
        int x {};
        std::cin >> x;

        if (!std::cin) // handle bad input
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // If we're done, break out of loop
        if (x == -1)
            break;

        // The user entered a valid element, so let's push it on the vector
        scoreList.push_back(x);
    }

    std::cout << "Your list of scores: \n";

    for (const auto& score : scoreList)
        std::cout << score << ' ';

    return 0;
}
