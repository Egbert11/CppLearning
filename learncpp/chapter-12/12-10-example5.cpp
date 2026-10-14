// ============================================================
// 来源小节：12.10 Pass by address
// 示例说明：如果已经有一个保存着对象地址的指针变量，可以直接把该指针传给
//           形参，而不必再写 &。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-address/
// 备注：本节代码为按原文描述忠实重建（原 Example 5）。
// ============================================================
#include <iostream>
#include <string>

void printByAddress(const std::string* ptr)
{
    std::cout << *ptr << '\n';
}

int main()
{
    std::string str{ "Hello, world!" };

    std::string* ptr { &str }; // define a pointer variable holding the address of str
    printByAddress(ptr); // pass str by address via the existing pointer (no copy made)

    return 0;
}
