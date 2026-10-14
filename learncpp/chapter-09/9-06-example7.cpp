// 来源小节：9.6 Assert and static_assert
// 示例说明：用断言记录"尚未实现"的功能——字符串字面量总为真，断言实际取决于 moved：
//           当 moved 为 false 时整个表达式为假，断言触发并带上说明文字。
// 原文链接：https://www.learncpp.com/cpp-tutorial/assert-and-static_assert/
//
// 编译：g++ -std=c++20 -Wall 9-06-example7.cpp -o a
// 说明：这里 moved 为 false，表示"学生刚被转到另一间教室"这一情形尚未实现，因此断言触发。
//       预期信息形如：
//       Assertion failed: moved && "Need to handle case where student was just moved to another classroom",
//       file ...
// 警告：本程序运行到断言处会异常终止（非零退出），属预期行为。
//
// 本节代码为按原文描述重建。

#include <cassert>  // for assert
#include <iostream>

int main()
{
    // We have implemented some cases but not yet the "student was just moved to
    // another classroom" case, so "moved" is false here.
    bool moved{ false };

    assert(moved && "Need to handle case where student was just moved to another classroom");

    std::cout << "Handled the student\n";

    return 0;
}
