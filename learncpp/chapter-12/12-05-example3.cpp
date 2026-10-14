// ============================================================
// 来源小节：12.5 Pass by lvalue reference
// 示例说明：改用按引用传递（形参类型改为 std::string&）——实参绑定到
//           引用形参，不发生拷贝。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 3）。
// ============================================================
#include <iostream>
#include <string>

void printValue(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

int main()
{
    std::string x { "Hello, world!" };

    printValue(x); // x is now passed by reference into reference parameter y (inexpensive)

    return 0;
}

// 预期输出：
// Hello, world!
