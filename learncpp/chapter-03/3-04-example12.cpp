// 来源小节：3.4 Basic debugging tactics
// 示例说明：修复版——去掉 return 语句里多余的 -- 运算符，程序给出正确结果。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
//
// 预期输出（用户依次输入 4 和 3）：
//   main() called
//   getUserInput() called
//   Enter a number: 4
//   getUserInput::x = 4
//   main::x = 4
//   getUserInput() called
//   Enter a number: 3
//   getUserInput::x = 3
//   main::y = 3
//   add() called (x=4, y=3)
//   main::z = 7
//   printResult() called (z=7)
//   The answer is: 7

#include <iostream>

int add(int x, int y)
{
std::cerr << "add() called (x=" << x << ", y=" << y << ")\n";
    return x + y;
}

void printResult(int z)
{
std::cerr << "printResult() called (z=" << z << ")\n";
    std::cout << "The answer is: " << z << '\n';
}

int getUserInput()
{
std::cerr << "getUserInput() called\n";
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
std::cerr << "getUserInput::x = " << x << '\n';
    return x; // removed -- before x
}

int main()
{
std::cerr << "main() called\n";
    int x{ getUserInput() };
std::cerr << "main::x = " << x << '\n';
    int y{ getUserInput() };
std::cerr << "main::y = " << y << '\n';

    int z{ add(x, y) };
std::cerr << "main::z = " << z << '\n';
    printResult(z);

    return 0;
}
