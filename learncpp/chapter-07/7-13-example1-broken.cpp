// 来源小节：7.13 Using declarations and using directives
// 示例说明：经典的 Hello World —— 用 using 指令导入整个 std。可编译，但是过时/坏实践：
//           它把 std 中所有名字都拉进全局命名空间，极易冲突。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/
//
// 本节示例为按原文描述重建（对应原文 Example 1）。
// 预期输出：Hello world!

#include <iostream>
using namespace std; // 坏实践：导入整个 std

int main()
{
    cout << "Hello world!\n";
    return 0;
}
