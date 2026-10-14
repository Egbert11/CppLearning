// 来源小节：1.3 Introduction to objects and variables
// 示例说明：把四种不同类型的字面量（literal）输出到屏幕。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-objects-and-variables/
//
// 说明：原文没有给出输出块；这些语句若连续输出会连在一起，例如 5-6.7HHello。

#include <iostream> // for std::cout

int main()
{
    std::cout << 5;       // print the literal number `5`
    std::cout << -6.7;    // print the literal number `-6.7`
    std::cout << 'H';     // print the literal character `H`
    std::cout << "Hello"; // print the literal text `Hello`

    return 0;
}
