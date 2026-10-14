// 来源小节：7.11 Static local variables
// 示例说明：自动（默认）持久期 —— 每次调用 incrementAndPrint() 都重建 value，故每次都从 1 起。
// 原文链接：https://www.learncpp.com/cpp-tutorial/static-local-variables/
//
// 本节示例为按原文描述重建（对应原文 Example 1）。
// 预期输出：
// 2
// 2
// 2

#include <iostream>

void incrementAndPrint()
{
    int value{ 1 }; // 默认自动持久期 (automatic duration by default)
    ++value;
    std::cout << value << '\n';
} // value 在此销毁

int main()
{
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}
