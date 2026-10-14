// ============================================================
// 来源小节：12.5 Pass by lvalue reference
// 示例说明：非 const 引用形参只能接受可修改左值——const 变量和右值
//           （如字面量）都不能传入，这大幅限制了非 const 按引用传递
//           的适用范围。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/
// !! -error：预期编译失败，勿修复。
//   预期错误：printValue(z) 处 binding reference of type 'int&' to 'const int'
//             discards qualifiers；printValue(5) 处 cannot bind non-const
//             lvalue reference of type 'int&' to an rvalue。
// 备注：本节代码为按原文描述忠实重建（原 Example 7）。
// ============================================================
#include <iostream>

void printValue(int& y) // y only accepts modifiable lvalues
{
    std::cout << y << '\n';
}

int main()
{
    int x { 5 };
    printValue(x); // ok: x is a modifiable lvalue

    const int z { 5 };
    printValue(z); // error: z is a non-modifiable lvalue

    printValue(5); // error: 5 is an rvalue

    return 0;
}
