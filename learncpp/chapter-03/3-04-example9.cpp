// 来源小节：3.4 Basic debugging tactics
// 示例说明：第二个有 bug 的程序——getUserInput 的 return 语句里多写了一个 --（return --x;）。
//           该程序含原文故意保留的 bug（这正是被调试的对象），输出与原文记录一致。
// 原文链接：https://www.learncpp.com/cpp-tutorial/basic-debugging-tactics/
//
// 预期输出（用户依次输入 4 和 3）：
//   Enter a number: 4
//   Enter a number: 3
//   The answer is: 5
// （注：用户本意是 4 + 3 = 7，但每个输入都被 -- 减 1，变成 3 + 2 = 5。）

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
    return --x; // 多写了一个 --（这正是 bug）
}

int main()
{
    int x{ getUserInput() };
    int y{ getUserInput() };

    int z { add(x, y) };
    printResult(z);

    return 0;
}
