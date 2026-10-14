// 来源小节：3.4 Basic debugging tactics
// 示例说明：再在 getUserInput 内部加一条调试语句，检查它读入的局部值 x；
//           对比 main::x 为 3 而 getUserInput::x 为 4，即可锁定 return --x; 有问题。
//           该程序仍含原文故意保留的 bug（return --x;）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
//
// 预期输出（用户依次输入 4 和 3）：
//   main() called
//   getUserInput() called
//   Enter a number: 4
//   getUserInput::x = 4
//   main::x = 3
//   getUserInput() called
//   Enter a number: 3
//   getUserInput::x = 3
//   main::y = 2
//   add() called (x=3, y=2)
//   main::z = 5
//   printResult() called (z=5)
//   The answer is: 5
//
// 可疑的那一行：return --x;

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
std::cerr << "getUserInput::x = " << x << '\n'; // added this additional line of debugging
    return --x; // 多写了一个 --（这正是 bug）
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
