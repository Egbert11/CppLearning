// 来源小节：1.5 Introduction to iostream: cout, cin, and endl
// 示例说明：用 std::cin 从键盘读取一个整数并回显。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/
//
// 示例运行（用户输入 4）：
//   Enter a number: 4
//   You entered 4

#include <iostream>

int main()
{
    std::cout << "Enter a number: "; // ask user for a number

    int x{};       // define variable x to hold user input (and value-initialize it)
    std::cin >> x; // get number from the keyboard and store it in variable x

    std::cout << "You entered " << x << '\n';

    return 0;
}
