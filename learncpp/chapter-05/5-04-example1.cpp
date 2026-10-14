// ============================================================
// 来源小节：5.4 The as-if rule and compile-time optimization
// 示例说明：初始程序。3 + 4 的操作数都是字面量，可被常量折叠在
//           编译期求值。预期输出：7
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-as-if-rule-and-compile-time-optimization/
// ============================================================
#include <iostream>

int main()
{
    int x { 3 + 4 };
    std::cout << x << '\n';

    return 0;
}
