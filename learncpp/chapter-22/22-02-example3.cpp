// ============================================================
// 来源小节：22.2 R-value references
// 示例说明：用字面量初始化右值引用会创建临时对象；通过右值引用可以
//           修改该临时对象（临时对象通常不可见也无法直接修改）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/rvalue-references/
// 预期输出：
//   10
// 备注：本节代码为按原文描述重建（原 Example 3）。
// ============================================================
#include <iostream>

int main()
{
    int&& rref{ 5 }; // because we're initializing an r-value reference with a literal, a temporary with value 5 is created here
    rref = 10;
    std::cout << rref << '\n';

    return 0;
}
