// 来源小节：8.12 Halts (exiting your program early)
// 示例说明：用 std::atexit() 注册 cleanup()，使其在 std::exit() 时自动运行
// 原文链接：https://www.learncpp.com/cpp-tutorial/halts-exiting-your-program-early/
// 预期输出：1 换行 cleanup!
// 注意：注册时使用 cleanup（函数名）而非 cleanup()（调用）。

#include <cstdlib> // for std::exit()
#include <iostream>

void cleanup()
{
    // code here to do any kind of cleanup required
    std::cout << "cleanup!\n";
}

int main()
{
    // register cleanup() to be called automatically when std::exit() is called
    std::atexit(cleanup); // note: we use cleanup rather than cleanup() since we're not making a function call to cleanup() right now

    std::cout << 1 << '\n';

    std::exit(0); // terminate and return status code 0 to operating system

    // The following statements never execute
    std::cout << 2 << '\n';

    return 0;
}
