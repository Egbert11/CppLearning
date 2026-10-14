// 来源小节：8.12 Halts (exiting your program early)
// 示例说明：从 main() 显式调用 std::exit() 提前结束程序，并手动调用清理函数
// 原文链接：https://www.learncpp.com/cpp-tutorial/halts-exiting-your-program-early/
// 预期输出：1 换行 cleanup!
// 注意：std::exit() 之后的语句不会执行。

#include <cstdlib> // for std::exit()
#include <iostream>

void cleanup()
{
    // code here to do any kind of cleanup required
    std::cout << "cleanup!\n";
}

int main()
{
    std::cout << 1 << '\n';
    cleanup();

    std::exit(0); // terminate and return status code 0 to operating system

    // The following statements never execute
    std::cout << 2 << '\n';

    return 0;
}
