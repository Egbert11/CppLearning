// 来源小节：1.5 Introduction to iostream: cout, cin, and endl
// 示例说明：用一条语句 std::cin >> x >> y; 读取两个整数（多个值之间用空白分隔）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/
//
// 示例运行（用户输入 5 6）：
//   Enter two numbers separated by a space: 5 6
//   You entered 5 and 6
//
// 备注：原文还演示了"分成两条语句"的等价写法：
//   std::cin >> x;
//   ...
//   std::cin >> y;
// 若两次数值在同一行输入（如 `4 5`），第二次提取不会等待，因为 5 已在缓冲区中。

#include <iostream>

int main()
{
    std::cout << "Enter two numbers separated by a space: ";

    int x{};
    int y{};
    std::cin >> x >> y; // get two numbers (separated by whitespace) from the keyboard

    std::cout << "You entered " << x << " and " << y << '\n';

    return 0;
}
