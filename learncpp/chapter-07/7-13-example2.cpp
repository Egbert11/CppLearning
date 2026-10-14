// 来源小节：7.13 Using declarations and using directives
// 示例说明：改用 using 声明只引入 cout 这一个名字，比导入整个命名空间安全。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/
//
// 本节示例为按原文描述重建（对应原文 Example 2）。
// 预期输出：Hello world!

#include <iostream>
using std::cout; // using 声明：只引入 std::cout

int main()
{
    cout << "Hello world!\n";
    return 0;
}
