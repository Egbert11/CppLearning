// 来源小节：9.4 Detecting and handling errors
// 示例说明：用 halt 语句处理致命（不可恢复）错误——y 为 0 时打印错误后调用 std::exit(1)
//           终止程序，否则返回 x / y。这里展示的是"终止程序"这一策略。
// 原文链接：https://www.learncpp.com/cpp-tutorial/detecting-and-handling-errors/
//
// 编译：g++ -std=c++20 -Wall 9-04-example7.cpp -o a
// 第二个数为 0 时预期输出：Error: Could not divide by zero
//                      并以状态码 1 退出程序。
//
// 本节代码为按原文描述重建。

#include <cstdlib>  // for std::exit
#include <iostream>

double doIntDivision(int x, int y)
{
    if (y == 0)
    {
        std::cerr << "Error: Could not divide by zero\n";
        std::exit(1); // halt the program
    }

    return static_cast<double>(x) / y;
}

int main()
{
    std::cout << doIntDivision(10, 2) << '\n';

    return 0;
}
