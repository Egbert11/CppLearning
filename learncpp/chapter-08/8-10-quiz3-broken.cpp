// 来源小节：8.10 For statements（本节 Quiz 第 3 题——找出循环的问题）
// 示例说明：unsigned int 的倒数循环永远无法结束。
//           因为 unsigned 变量不可能小于 0，条件 i >= 0 恒为真。
// 原文链接：https://www.learncpp.com/cpp-tutorial/for-statements/
// 注意：这是有意演示的无限循环，运行不会自行结束——请勿运行到结束。
// 结论：除非必要，避免在 unsigned 变量上循环。

#include <iostream>

int main()
{
    // Print all numbers from 9 to 0
    for (unsigned int i{ 9 }; i >= 0; --i) // i >= 0 is always true for unsigned!
        std::cout << i << ' '; // prints 9 8 7 ... 1 0 4294967295 4294967294 ...

    std::cout << '\n';

    return 0;
}
