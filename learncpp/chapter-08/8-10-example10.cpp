// 来源小节：8.10 For statements
// 示例说明：for (;;) 无限循环，等价于 while (true)；省略条件时标准视为 true
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 注意：这是有意演示的无限循环，运行不会自行结束——请勿运行到结束。
// （作者建议：避免这种写法，改用 while (true)）

#include <iostream>

int main()
{
    for (;;) // infinite loop, equivalent to while (true)
        std::cout << "loop\n";

    return 0; // unreachable
}
