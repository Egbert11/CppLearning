// 来源小节：10.4 Narrowing conversions, list initialization, and constexpr initializers
// 示例说明：源值要到运行期才知道，编译器无法判断符号/无符号转换是否保值，因此可能
//           仍发出警告（用户输入 5 或 -5）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/narrowing-conversions-list-initialization-and-constexpr-initializers/
//
// 编译：g++ -std=c++20 -Wall 10-04-example4.cpp -o a
//       注：符号/无符号警告默认关闭（GCC 下需 -Wsign-conversion 才提示）。
//
// 本节代码为按原文描述重建。

#include <iostream>

void print(unsigned int u) // note: unsigned
{
    std::cout << u << '\n';
}

int main()
{
    // --- 原文示例片段 ---
    std::cout << "Enter an integral value: ";
    int n{};
    std::cin >> n; // enter 5 or -5
    print(n);      // conversion to unsigned may or may not preserve value
    // --- 原文示例片段结束 ---

    return 0;
}
