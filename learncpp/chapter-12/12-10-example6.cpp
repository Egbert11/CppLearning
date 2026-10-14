// ============================================================
// 来源小节：12.10 Pass by address
// 示例说明：形参是指向非 const 的指针时，函数可以通过它修改实参，修改在
//           调用返回后依然有效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address/
// 预期输出：
//   x = 5
//   x = 6
// 备注：本节代码为按原文描述忠实重建（原 Example 6）。
// ============================================================
#include <iostream>

void changeValue(int* ptr) // note: ptr is a pointer to a non-const int
{
    *ptr = 6; // change the value at the address being held by ptr
}

int main()
{
    int x { 5 };
    std::cout << "x = " << x << '\n';

    changeValue(&x); // we pass the address of x, so changeValue() can modify x

    std::cout << "x = " << x << '\n';

    return 0;
}
