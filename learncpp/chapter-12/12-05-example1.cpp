// ============================================================
// 来源小节：12.5 Pass by lvalue reference
// 示例说明：按值传递 int——实参被拷贝进形参，形参在函数结束时销毁；
//           基本类型拷贝很廉价，无妨。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 1）。
// ============================================================
#include <iostream>

void printValue(int y)
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    int x { 2 };

    printValue(x); // x is passed by value (copied) into parameter y (inexpensive)

    return 0;
}

// 预期输出：
// 2
