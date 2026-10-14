// 来源小节：3.5 More debugging tactics
// 示例说明：把调试语句条件化——用 #define ENABLE_DEBUG 配合 #ifdef / #endif 包裹每条调试语句。
//           这样调试代码可以留在源码中，只需注释掉 #define 这一行即可整体禁用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/more-debugging-tactics/
//
// 预期输出（用户输入 4）：
//   main() called
//   getUserInput() called
//   Enter a number: 4
//   You entered: 4
// 若把 #define ENABLE_DEBUG 一行注释掉，则所有调试输出消失，只剩：
//   Enter a number: 4
//   You entered: 4

#include <iostream>

#define ENABLE_DEBUG // 注释掉这一行即可关闭调试输出

int getUserInput()
{
#ifdef ENABLE_DEBUG
    std::cerr << "getUserInput() called\n";
#endif

    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
#ifdef ENABLE_DEBUG
    std::cerr << "main() called\n";
#endif

    int x{ getUserInput() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}
