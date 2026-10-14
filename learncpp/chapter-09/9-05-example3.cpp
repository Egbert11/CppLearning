// 来源小节：9.5 std::cin and handling invalid input
// 示例说明：错误情形 2（多余输入）的修正——演示三种清除多余输入的方式：
//           (1) std::cin.ignore(100, '\n') 清最多 100 个字符或到换行；
//           (2) std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
//               禁用计数检查，清到并包含下一个换行；
//           (3) 把 (2) 封装成可复用的 ignoreLine() 辅助函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
//
// 编译：g++ -std=c++20 -Wall 9-05-example3.cpp -o a
// 这是交互式程序，需要用户输入。输入 5*7 时 getDouble() 提取 5 并丢弃 *7。
//
// 本节代码为按原文描述重建（合并原文示例 3、4、5、6）。

#include <iostream>
#include <limits> // for std::numeric_limits

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    std::cout << "Enter a decimal number: ";
    double x{};
    std::cin >> x;

    // 原文示例 3：std::cin.ignore(100, '\n'); // clear up to 100 characters or until a newline
    // 原文示例 4：std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // 原文示例 5/6：封装成 ignoreLine()，提取后立即调用
    ignoreLine(); // remove any extraneous input
    return x;
}

int main()
{
    double x{ getDouble() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}
