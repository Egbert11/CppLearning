// ============================================================
// 来源小节：22.2 R-value references
// 示例说明：左值引用用左值初始化；右值引用用右值初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/rvalue-references/
// 预期输出：
//   10 20
// 备注：本节代码为按原文描述重建（原 Example 1，补出走一份可编译的演示）。
// ============================================================
#include <iostream>

int main()
{
    int x{ 5 };
    int& lref{ x };   // l-value reference initialized with l-value x
    int&& rref{ 5 };  // r-value reference initialized with r-value 5

    lref = 10;  // 通过左值引用修改 x
    rref = 20;  // 通过右值引用修改那个临时对象

    std::cout << lref << ' ' << rref << '\n';

    return 0;
}
