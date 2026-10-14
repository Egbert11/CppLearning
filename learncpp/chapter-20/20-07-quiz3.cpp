// 来源小节：20.7 Lambda captures（Quiz 2）
// 示例说明："平方数猜谜"游戏：程序随机选一个乘数（2..6），生成一串由连续整数平方后再乘该乘数
//           得到的数字；玩家逐一猜这些数字，猜中就移除，猜错则提示最接近的剩余数字并结束。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lambda-captures/
// 说明：本节代码按原文解答的思路重建（原文解答由 config 命名空间与若干辅助函数组成）。
//       与原文一致：题目文字里写的是"between 2 and 4"，但实际实现使用的是 2..6 的乘数范围。
// Best practice：只在该值很短、且类型显而易见时才在捕获里初始化变量（这里用于 findClosestNumber）。
// 交互运行示例：
//   Start where? 4
//   How many? 3
//   I generated 3 square numbers. Do you know what each number is after multiplying it by 4?
//   > 64
//   Nice! 2 number(s) left.
//   > 100
//   Nice! 1 number(s) left.
//   > 144
//   Nice! You found all numbers, good job!

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

using Numbers = std::vector<int>;

namespace config
{
    constexpr int multiplierMin{ 2 };
    constexpr int multiplierMax{ 6 };
}

int getRandomInt(int min, int max)
{
    static std::mt19937 mt{ std::random_device{}() };
    return std::uniform_int_distribution(min, max)(mt); // CTAD deduces std::uniform_int_distribution<int>
}

// Generates @count numbers starting at @start and multiplied by @multiplier.
Numbers generateNumbers(int start, int count, int multiplier)
{
    Numbers numbers(static_cast<std::size_t>(count));

    for (int i = 0; i < count; ++i)
    {
        int number{ start + i };

        numbers[static_cast<std::size_t>(i)] = number * number * multiplier;
    }

    return numbers;
}

Numbers setupGame()
{
    int start{};
    std::cout << "Start where? ";
    std::cin >> start;

    int count{};
    std::cout << "How many? ";
    std::cin >> count;

    int multiplier{ getRandomInt(config::multiplierMin, config::multiplierMax) };
    std::cout << "I generated " << count
              << " square numbers. Do you know what each number is after multiplying it by "
              << multiplier << "?\n";

    return generateNumbers(start, count, multiplier);
}

int getUserGuess()
{
    int guess{};
    std::cout << "> ";
    std::cin >> guess;

    return guess;
}

// Searches for @guess in @numbers and removes it.
// Returns true if the value was found (and removed).
bool findAndRemove(Numbers& numbers, int guess)
{
    auto found{ std::find(numbers.begin(), numbers.end(), guess) };

    if (found == numbers.end())
        return false;

    numbers.erase(found);
    return true;
}

// Find the number in @numbers that is closest to @guess.
int findClosestNumber(const Numbers& numbers, int guess)
{
    // --- 原文示例片段 ---
    return *std::min_element(numbers.begin(), numbers.end(),
                             [=](int a, int b) {
                                 return std::abs(a - guess) < std::abs(b - guess);
                             });
    // --- 原文示例片段结束 ---
}

void printSuccess(const Numbers& numbers)
{
    std::cout << "Nice! ";

    if (numbers.empty())
    {
        std::cout << "You found all numbers, good job!\n";
        return;
    }

    std::cout << numbers.size() << " number(s) left.\n";
}

void printFailure(const Numbers& numbers, int guess)
{
    std::cout << guess << " is wrong!\n";

    std::cout << "Try " << findClosestNumber(numbers, guess) << " next time.\n";
}

int main()
{
    Numbers numbers{ setupGame() };

    while (true)
    {
        int guess{ getUserGuess() };

        if (!findAndRemove(numbers, guess))
        {
            printFailure(numbers, guess);
            break;
        }

        printSuccess(numbers);

        if (numbers.empty())
            break;
    }

    return 0;
}
