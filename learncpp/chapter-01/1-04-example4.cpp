// 来源小节：1.4 Variable assignment and initialization
// 示例说明：值初始化（空花括号）会把变量初始化为 0；并演示 { 0 } 与 {} 的取舍。
// 原文链接：https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
//
// 运行说明：本程序会等待用户输入一个整数（因为示例 12b 用 std::cin 立即替换了初值）。
// 预期输出形如（示例输入 42）：
//   0 0
//   42
// 其中第一行是 x 与 width（均为值初始化的 0），第二行是你输入的 y。

#include <iostream>

int main()
{
    // --- 原文示例片段：值初始化 / 零初始化 ---
    int width {}; // value-initialization / zero-initialization to value 0
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：确实会用到这个 0，因此用 { 0 } ---
    int x { 0 };    // direct-list-initialization with initial value 0
    std::cout << x; // we're using that 0 value here
    // --- 原文示例片段结束 ---

    std::cout << ' ';
    std::cout << width; // prints the zero-initialized value 0
    std::cout << '\n';

    // --- 原文示例片段：值只是临时的，马上会被替换，因此用 {} ---
    int y {};      // value initialization
    std::cin >> y; // we're immediately replacing that value so an explicit 0 would be meaningless
    // --- 原文示例片段结束 ---

    std::cout << y << '\n';

    return 0;
}
