// ============================================================
// 来源小节：12.10 Pass by address
// 示例说明：按地址传递要求实参有地址，因此只能传左值。这里 printByValue(5)
//           与 printByReference(5) 都合法（前者复制，后者是 const 引用），
//           但 printByAddress(&5) 非法——不能取右值的地址。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address/
// !! -error：预期编译失败，请勿修复。
//    预期错误：lvalue required as unary '&' operand（取地址运算需要左值）。
// 备注：本节代码为按原文描述忠实重建（原 Example 13）。
// ============================================================
#include <iostream>

void printByValue(int val)
{
    std::cout << val << '\n';
}

void printByReference(const int& ref)
{
    std::cout << ref << '\n';
}

void printByAddress(const int* ptr)
{
    std::cout << *ptr << '\n';
}

int main()
{
    printByValue(5);     // okay: 5 is copied
    printByReference(5); // okay: const reference can bind to an rvalue

    printByAddress(&5);  // error: can not take the address of an rvalue

    return 0;
}
