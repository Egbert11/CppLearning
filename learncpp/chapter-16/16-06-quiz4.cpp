// ============================================================
// 来源小节：16.6 Arrays and loops
// 示例说明：Quiz #4 解答（额外加分）——把 getValidNumber 泛化为
//           getValidNumber(std::string_view prompt, T low, T high)，可处理 double。
// 原文链接：https://www.learncpp.com/cpp-tutorial/arrays-and-loops/
// 预期输出（示例会话）：
//   Enter a number between 1 and 9: 4.5
//   You entered 4.5
// 备注：本节代码为按原文描述重建（需要标准输入）。
// ============================================================
#include <iostream>
#include <limits>
#include <string_view>

template <typename T>
T getValidNumber(std::string_view prompt, T low, T high)
{
    T num{};
    do
    {
        std::cout << prompt;
        std::cin >> num;

        if (!std::cin) // if the previous extraction failed
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
        }
    } while (num < low || num > high);

    return num;
}

int main()
{
    auto num { getValidNumber("Enter a number between 1 and 9: ", 1.0, 9.0) };

    std::cout << "You entered " << num << '\n';

    return 0;
}
