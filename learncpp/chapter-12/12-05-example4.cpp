// ============================================================
// 来源小节：12.5 Pass by lvalue reference
// 示例说明：比较值形参与引用形参的地址——值形参地址与实参不同（是拷贝），
//           引用形参的地址与实参相同（就是实参本身）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 4）。
//       地址的具体数值因运行而异，下面注释只是某次运行的示例。
// ============================================================
#include <iostream>

void printAddresses(int val, int& ref)
{
    std::cout << "The address of the value parameter is: " << &val << '\n';
    std::cout << "The address of the reference parameter is: " << &ref << '\n';
}

int main()
{
    int x { 5 };
    std::cout << "The address of x is: " << &x << '\n';
    printAddresses(x, x);

    return 0;
}

// 某次运行的预期输出（地址随运行变化）：
// The address of x is: 0x7ffd16574de0
// The address of the value parameter is: 0x7ffd16574de4
// The address of the reference parameter is: 0x7ffd16574de0
