// 来源小节：3.4 Basic debugging tactics
// 示例说明：手法 #3（打印值）引入的有 bug 程序——add(x, 5) 传入了错误的实参，结果不对。
//           该程序含原文故意保留的 bug（这正是被调试的对象），输出与原文记录一致。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
//
// 预期输出（用户依次输入 4 和 3）：
//   Enter a number: 4
//   Enter a number: 3
//   The answer is: 9
// （注：用户本意是 4 + 3 = 7，但程序把第二个数硬编码成了 5，故得到 9。）

#include <iostream>

int add(int x, int y)
{
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
    int y{ getUserInput() };

    int z{ add(x, 5) }; // 这里本应是 add(x, y)，却硬编码成了 5
    printResult(z);

    return 0;
}
