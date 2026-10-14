// 来源小节：7.13 Using declarations and using directives
// 示例说明：两条 using 指令分别导入命名空间 A 与 B，二者都定义了 x，
//           于是非限定名 x 有歧义，编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/
//
// 本节示例为按原文描述重建（对应原文 Example 5）。
// ※ 预期编译失败（勿修复）：g++ 报 "reference to 'x' is ambiguous"。
//   修复方式：改用 using 声明，或对使用处显式写 A::x / B::x。

#include <iostream>

namespace A { int x { 10 }; }
namespace B { int x { 20 }; }

using namespace A;
using namespace B;

int main()
{
    std::cout << x << '\n'; // 歧义：是 A::x 还是 B::x？→ 编译错误

    return 0;
}
