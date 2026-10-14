// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：以 const 引用返回一个临时值（5）。临时值在函数返回时被销毁，
//           调用方的 ref 于是成为悬垂引用，使用它是未定义行为。
//           注意：引用“生命周期延长”不能跨越函数边界。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// !! -ub：未定义行为演示，可编译（gcc 会给出警告）。
// 备注：本节代码为按原文描述忠实重建（原 Example 5）。
// ============================================================
#include <iostream>

const int& returnByConstReference()
{
    return 5; // returns a dangling reference to a temporary
}

int main()
{
    const int& ref { returnByConstReference() }; // dangling reference

    std::cout << ref << '\n'; // undefined behavior

    return 0;
}
