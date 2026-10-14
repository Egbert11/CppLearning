// 来源小节：1.5 Introduction to iostream: cout, cin, and endl
// 示例说明：读取三个整数并按句子输出（原文测验第 2 题）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/
//
// 示例运行（用户输入 4 5 6）：
//   Enter three numbers: 4 5 6
//   You entered 4, 5, and 6.
//
// 备注：句末的 ".\n" 必须用双引号，因为它不止一个字符。

#include <iostream>

int main()
{
    std::cout << "Enter three numbers: ";

    int x{};
    int y{};
    int z{};
    std::cin >> x >> y >> z;

    std::cout << "You entered " << x << ", " << y << ", and " << z << ".\n";

    return 0;
}
