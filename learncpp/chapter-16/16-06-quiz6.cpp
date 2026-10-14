// ============================================================
// 来源小节：16.6 Arrays and loops
// 示例说明：Quiz #6 解答——fizzbuzz()：并行的 divisors 与 words 两个 vector，
//           用 assert 断言二者长度一致，对每个数检查所有除数，无匹配时打印数字本身。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-and-loops/
// 预期输出（前 21 行）：
//   1
//   2
//   fizz
//   4
//   buzz
//   fizz
//   pop
//   8
//   fizz
//   buzz
//   bang
//   fizz
//   jazz
//   pop
//   fizzbuzz
//   16
//   pow
//   fizz
//   boom
//   buzz
//   fizzpop
// 备注：本节代码为按原文描述重建。原示例以较大 count 调用，这里打印到 150。
//       Tip：由于两个 vector 是常量，用 constexpr std::array 更好（见 17.1）。
// ============================================================
#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

void fizzbuzz(int count)
{
    // The divisors for the defined words (in the order the words must be printed)
    static const std::vector<int> divisors { 3, 5, 7, 11, 13, 17, 19 };

    // The words corresponding to the divisors
    static const std::vector<std::string_view> words { "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom" };

    // The words array must be the same length as the divisors array
    assert(std::size(divisors) == std::size(words) && "fizzbuzz(): size mismatch.");

    for (int i{ 1 }; i <= count; ++i)
    {
        bool printed{ false };

        // Check to see if our number is divisible by any of the divisors
        for (std::size_t j{ 0 }; j < divisors.size(); ++j)
        {
            if (i % divisors[j] == 0)
            {
                std::cout << words[j];
                printed = true;
            }
        }

        // If we did not print any words for this number, print the number
        if (!printed)
            std::cout << i;

        std::cout << '\n';
    }
}

int main()
{
    fizzbuzz(150);

    return 0;
}
