// 来源小节：8.12 Halts (exiting your program early)
// 示例说明：用 std::abort() 导致异常终止（不做任何清理）
// 原文链接：https://www.learncpp.com/cpp-tutorial/halts-exiting-your-program-early/
// 预期输出：1（随后程序异常终止，可能伴随 abort 提示）

#include <cstdlib> // for std::abort()
#include <iostream>

int main()
{
    std::cout << 1 << '\n';
    std::abort();

    // The following statements never execute
    std::cout << 2 << '\n';

    return 0;
}
