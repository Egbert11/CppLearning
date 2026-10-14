// ============================================================
// 来源小节：12.5 Pass by lvalue reference
// 示例说明：按值传递时，函数内对形参的修改只作用于副本，实参不受影响。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 5）。
// ============================================================
#include <iostream>

void addOne(int y) // y is a copy of x
{
    ++y; // this modifies the copy of x, not the actual object x
}

int main()
{
    int x { 5 };

    std::cout << "value = " << x << '\n';

    addOne(x);

    std::cout << "value = " << x << '\n'; // x has not been modified

    return 0;
}

// 预期输出：
// value = 5
// value = 5
