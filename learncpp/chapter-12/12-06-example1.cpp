// ============================================================
// 来源小节：12.6 Pass by const lvalue reference
// 示例说明：const 引用形参可绑定三种实参：可修改左值、不可修改左值、
//           右值（字面量）——因为对 const 的引用绑定范围更宽。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 1）。
// ============================================================
#include <iostream>

void printRef(const int& y) // y is a const reference
{
    std::cout << y << '\n';
}

int main()
{
    int x { 5 };
    printRef(x); // ok: x is a modifiable lvalue, y binds to x

    const int z { 5 };
    printRef(z); // ok: z is a non-modifiable lvalue, y binds to z

    printRef(5); // ok: 5 is rvalue literal, y binds to temporary int object

    return 0;
}

// 预期输出：
// 5
// 5
// 5
