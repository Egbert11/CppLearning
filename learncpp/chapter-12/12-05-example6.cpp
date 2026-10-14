// ============================================================
// 来源小节：12.5 Pass by lvalue reference
// 示例说明：按引用传递时，修改形参就是修改实参，改动在函数返回后依然
//           存在——这让函数能修改传入的实参。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 6）。
// ============================================================
#include <iostream>

void addOne(int& y) // y is bound to the actual object x
{
    ++y; // this modifies the actual object x
}

int main()
{
    int x { 5 };

    std::cout << "value = " << x << '\n';

    addOne(x);

    std::cout << "value = " << x << '\n'; // x has been modified

    return 0;
}

// 预期输出：
// value = 5
// value = 6
