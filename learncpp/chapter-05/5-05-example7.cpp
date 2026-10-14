// ============================================================
// 来源小节：5.5 Constant expressions
// 示例说明：为什么编译期表达式必须是常量。x 起初值已知（5），
//           因此其使用可被优化；一旦从 std::cin 读入，值在编译期
//           就不再已知，之后的用法无法再被优化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-expressions/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 }; // x is known to the compiler (value 5)

    // The compiler could optimize any uses of x here to use the value 5 instead.

    std::cout << "Enter a new value for x: ";
    std::cin >> x; // x is no longer known to the compiler

    // The compiler can no longer optimize uses of x below this point.
    // --- 原文示例片段结束 ---

    std::cout << x << '\n';

    return 0;
}
