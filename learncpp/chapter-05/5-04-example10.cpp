// ============================================================
// 来源小节：5.4 The as-if rule and compile-time optimization
// 示例说明：把 x 声明为 const，给编译器一个“值不会改变”的保证，
//           使常量传播（乃至把 x 完全优化掉）更可能发生。
//           预期输出：7
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-as-if-rule-and-compile-time-optimization/
// ============================================================
#include <iostream>

int main()
{
    const int x { 7 }; // x is now const
    std::cout << x << '\n';

    return 0;
}
