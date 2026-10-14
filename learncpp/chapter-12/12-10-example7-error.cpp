// ============================================================
// 来源小节：12.10 Pass by address
// 示例说明：把形参改为“指向 const 的指针”后，函数就不能通过它修改实参；
//           尝试赋值会编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address/
// !! -error：预期编译失败，请勿修复。
//    预期错误：assignment of read-only location '* ptr'（对只读位置赋值）。
// 备注：本节代码为按原文描述忠实重建（原 Example 7）。
// ============================================================
#include <iostream>

void changeValue(const int* ptr) // note: ptr is now a pointer to a const int
{
    *ptr = 6; // error: can not change const value
}

int main()
{
    int x { 5 };
    std::cout << "x = " << x << '\n';

    changeValue(&x);

    std::cout << "x = " << x << '\n';

    return 0;
}
