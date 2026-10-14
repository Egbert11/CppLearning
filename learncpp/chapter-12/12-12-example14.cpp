// ============================================================
// 来源小节：12.12 Return by reference and return by address
// 示例说明：函数返回非 const 引用时，调用方可以通过它赋值——把 max(a, b)
//           的返回值当左值使用，即把较大者改成 7。
// 原文链接：https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/
// 预期输出：57
// 备注：本节代码为按原文描述忠实重建（原 Example 14）。
// ============================================================
#include <iostream>

int& max(int& x, int& y)
{
    return (x > y) ? x : y;
}

int main()
{
    int a{ 5 };
    int b{ 6 };

    max(a, b) = 7; // sets the greater of a or b to 7 (here b)

    std::cout << a << b << '\n';

    return 0;
}
