// 来源小节：9.5 std::cin and handling invalid input
// 示例说明：把多余输入视为失败——hasUnextractedInput() 用 std::cin.eof() 与
//           std::cin.peek() 判断当前行是否还有未提取的输入；若有，则清掉并要求重输。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
//
// 编译：g++ -std=c++20 -Wall 9-05-example4.cpp -o a
// 这是交互式程序，需要用户输入。对 double 输入 "5x" 会被视为失败并重新提示。
//
// 本节代码为按原文描述重建（合并原文示例 7 与 13）。

#include <iostream>
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if std::cin has unextracted input on the current line, false otherwise
bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
    // equivalent: return !(std::cin.eof() || std::cin.peek() == '\n');
}

double getDouble()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;

        // If the previous extraction failed, put us back in 'normal' mode and
        // remove the bad input
        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
            continue;
        }

        // If the user entered only a number (and nothing else), we're done
        if (!hasUnextractedInput())
            return x;

        // Otherwise, discard the extraneous input and ask the user to try again
        ignoreLine();
        std::cout << "Oops, that input was invalid.  Please try again.\n";
    }
}

int main()
{
    double x{ getDouble() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}
