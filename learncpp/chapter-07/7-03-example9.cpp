// 来源小节：7.3 Local variables
// 示例说明：偶尔需要在更外层块里使用变量时，应把它声明在外层块中——若定义在内层块里，
//           它会过早销毁。（对应原文 Example 9）
// 原文链接：https://www.learncpp.com/cpp-tutorial/local-variables/
//
// 预期输出（输入 1）：
//   Enter an integer: 1
//   4
//   4
//
// ※ 本节示例为按原文描述重建，语义与原文一致。

#include <iostream>

int main()
{
    int y { 5 }; // We need y to be visible outside of the block below

    { // nested block
        std::cout << "Enter an integer: ";
        int x{};
        std::cin >> x;

        if (x == 0 || x == 1 || x == 2 || x == 3)
            y = 4;

        std::cout << y << '\n';
    } // if we had defined y in this block, it would be destroyed here

    std::cout << y << '\n'; // y still exists here

    return 0;
}
