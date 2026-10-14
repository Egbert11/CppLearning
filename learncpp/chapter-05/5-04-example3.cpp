// ============================================================
// 来源小节：5.4 The as-if rule and compile-time optimization
// 示例说明：常量折叠可作用于“仍须在运行期执行”的表达式内部的子表达式：
//           这里 3 + 4 可在编译期折叠为 7，而输出本身仍在运行期进行。
//           预期输出：7
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-as-if-rule-and-compile-time-optimization/
// ============================================================
#include <iostream>

int main()
{
    std::cout << 3 + 4 << '\n';

    return 0;
}
