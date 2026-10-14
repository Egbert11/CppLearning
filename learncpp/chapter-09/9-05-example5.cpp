// 来源小节：9.5 std::cin and handling invalid input
// 示例说明：错误情形 3（提取失败）的修正——检测失败后必须先 clear() 再 ignoreLine()；
//           并用 bool success { std::cin }; 记住结果，从而合并成功/失败两条路径。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
//
// 编译：g++ -std=c++20 -Wall 9-05-example5.cpp -o a
// 这是交互式程序，需要用户输入。对 double 输入 "a" 会提示重新输入，而不是死循环。
//
// 本节代码为按原文描述重建（合并原文示例 8、9、10）。

#include <iostream>
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a decimal number: ";
        double x{};
        std::cin >> x;

        // 原文示例 10：用 success 合并成功/失败两条路径
        bool success{ std::cin };

        // Whether we succeeded or failed, clear any bad/extraneous input.
        // clear() is called unconditionally; it is harmless if nothing failed.
        std::cin.clear(); // put us back in 'normal' operation mode
        ignoreLine();     // and remove the bad input

        if (success)
            return x; // we extracted a value, so return it

        // If extraction failed, we'll loop and try again
        std::cout << "Oops, that input is invalid.  Please try again.\n";
    }
}

int main()
{
    double x{ getDouble() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}
