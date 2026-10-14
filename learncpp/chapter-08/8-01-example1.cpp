// 来源小节：8.1 Control flow introduction
// 示例说明：一个"直线式"（straight-line）程序——每次运行都按相同顺序执行同样的语句，
//           用来演示程序的执行路径（execution path）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/control-flow-introduction/
//
// 编译：g++ -std=c++20 -Wall 8-01-example1.cpp -o a
//
// 本节代码为按原文描述重建（抓取工具无法逐字返回完整代码块）。

#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;

    std::cout << "You entered " << x << '\n';

    return 0;
}

// 原文说明：该程序的执行路径依次经过第 5、7、8、10、12 行（按原文行号）。
// 每次运行都走同一条路线，因此这是一个 straight-line program。
