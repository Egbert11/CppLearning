// ============================================================
// 来源小节：28.5 Stream states and input validation（原 Example 3）
// 示例说明：电话号码模板验证——inputMatches 用 std::map 把模板符号
//           '#'/'_'/'@'/'?' 映射到验证函数，再用 std::ranges::equal 逐字符比较。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-states-and-input-validation/
// 预期：需要交互输入；输入形如 "(123) 456-7890" 才通过。
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块）。
// ============================================================
#include <algorithm> // std::equal
#include <cctype> // std::isdigit, std::isspace, std::isalpha
#include <iostream>
#include <map>
#include <ranges>
#include <string>
#include <string_view>

bool inputMatches(std::string_view input, std::string_view pattern)
{
    if (input.length() != pattern.length())
    {
        return false;
    }

    // This table defines all special symbols that can match a range of user input
    // Each symbol is mapped to a function that determines whether the input is valid for that symbol
    static const std::map<char, int (*)(int)> validators{
      { '#', &std::isdigit },
      { '_', &std::isspace },
      { '@', &std::isalpha },
      { '?', [](int) { return 1; } }
    };

    // Before C++20, use
    // return std::equal(input.begin(), input.end(), pattern.begin(), [](char ch, char mask) -> bool {
    // ...

    return std::ranges::equal(input, pattern, [](char ch, char mask) -> bool {
        auto found{ validators.find(mask) };

        if (found != validators.end())
        {
            // The pattern's current element was found in the validators. Call the
            // corresponding function.
            return (*found->second)(ch);
        }

        // The pattern's current element was not found in the validators. The
        // characters have to be an exact match.
        return ch == mask;
        }); // end of lambda
}

int main()
{
    std::string phoneNumber{};

    do
    {
        std::cout << "Enter a phone number (###) ###-####: ";
        std::getline(std::cin, phoneNumber);
    } while (!inputMatches(phoneNumber, "(###) ###-####"));

    std::cout << "You entered: " << phoneNumber << '\n';
}
