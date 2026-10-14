// 来源小节：3.4 Basic debugging tactics
// 示例说明：在 add() 内部加入调试输出，暴露了传进来的实参 y 是 5 而不是用户输入的 3。
//           该程序仍含原文故意保留的 bug（实参硬编码为 5）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
//
// 预期输出（用户依次输入 4 和 3）：
//   Enter a number: 4
//   main::x = 4
//   Enter a number: 3
//   main::y = 3
//   add() called (x=4, y=5)
//   main::z = 9
//   The answer is: 9
//
// 罪魁祸首的那一行：int z{ add(x, 5) };

#include <iostream>

int add(int x, int y)
{
std::cerr << "add() called (x=" << x <<", y=" << y << ")\n";
    return x + y;
}

void printResult(int z)
{
    std::cout << "The answer is: " << z << '\n';
}

int getUserInput()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    int x{ getUserInput() };
std::cerr << "main::x = " << x << '\n';
    int y{ getUserInput() };
std::cerr << "main::y = " << y << '\n';

    int z{ add(x, 5) };
std::cerr << "main::z = " << z << '\n';
    printResult(z);

    return 0;
}
