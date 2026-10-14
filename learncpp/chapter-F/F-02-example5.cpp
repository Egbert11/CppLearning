// 来源小节：F.2 Constexpr functions (part 2)
// 示例说明：同一个 constexpr greater() 在四种不同语境下求值时机的差异。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constexpr-functions-part-2/
//
// 预期输出（示例输入 7）：
//   6 is greater!
//   6 is greater!
//   6 is greater!
//   7 is greater!
//
// 说明：本节代码为按原文描述重建（抓取工具无法逐字返回长代码块），语义与预期输出一致。
//       四种情况：
//       case 1 总是编译期求值；case 2 编译期或运行期皆可；
//       case 3 很可能运行期求值（as-if 规则下也可能编译期）；case 4 总是运行期求值。
//       第 4 种情况从 std::cin 读入，需要交互输入。
#include <iostream>

constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    // --- 原文示例片段 ---
    // case 1: always compile-time (a constant expression is required here)
    constexpr int g { greater(5, 6) };
    std::cout << g << " is greater!\n";

    // case 2: may be either; arguments are constant expressions, but the call
    // executes in a non-required context
    std::cout << greater(5, 6) << " is greater!\n";

    // case 3: likely runtime; value of x is known at compile-time (as-if rule may apply)
    int x{ 5 };
    std::cout << greater(x, 6) << " is greater!\n";

    // case 4: always runtime; x's value can't be known at compile-time
    std::cin >> x;
    std::cout << greater(x, 6) << " is greater!\n";
    // --- 原文示例片段结束 ---

    return 0;
}
