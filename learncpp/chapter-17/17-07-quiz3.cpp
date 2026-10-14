// ============================================================
// 来源小节：17.7 Introduction to C-style arrays
// 示例说明：Quiz #3 解答——用 constexpr C 风格数组保存平方数，循环提示输入
//           单个数字，判断它是否为完全平方数，输入 -1 退出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-c-style-arrays/
// 预期输出（示例）：
//            Enter a single digit integer, or -1 to quit: 4
//            4 is a perfect square
//            Enter a single digit integer, or -1 to quit: 5
//            5 is not a perfect square
//            Enter a single digit integer, or -1 to quit: -1
//            Bye
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>

namespace ProgramData
{
    constexpr int squares[] { 0, 1, 4, 9 }; // perfect squares of 0..3
}

bool matchSquare(int input)
{
    for (auto e : ProgramData::squares)
    {
        if (e == input)
            return true;
    }
    return false;
}

int main()
{
    while (true)
    {
        std::cout << "Enter a single digit integer, or -1 to quit: ";

        int input{};
        std::cin >> input;

        if (input == -1)
            break;

        if (matchSquare(input))
            std::cout << input << " is a perfect square\n";
        else
            std::cout << input << " is not a perfect square\n";
    }

    std::cout << "Bye\n";

    return 0;
}
