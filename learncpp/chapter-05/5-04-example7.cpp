// ============================================================
// 来源小节：5.4 The as-if rule and compile-time optimization
// 示例说明：常量传播后（x 被替换为 7），x 再也没有被使用，
//           于是它的定义成为死代码，可被死代码消除删除。
//           预期输出：7
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-as-if-rule-and-compile-time-optimization/
// ============================================================
#include <iostream>

int main()
{
    // 示例 5（常量传播后）: std::cout << x << '\n';  变为  std::cout << 7 << '\n';
    // 示例 8（死代码消除后）: 上面这行 x 的定义被整条删除，程序等价于 std::cout << 7 << '\n';

    int x { 7 }; // x is unused: the compiler can eliminate this definition entirely
    std::cout << 7 << '\n';

    return 0;
}
