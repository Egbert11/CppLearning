// 来源小节：7.13 Using declarations and using directives
// 示例说明：using 声明的正确位置 —— 先包含两个头文件（两个重载都已可见），
//           再写 using Foo::print; 因此 print(5) 调用 Foo::print(int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/
//
// 本节示例为按原文描述重建（对应原文 Example 11）。
// 反面（Example 12）：若把 using Foo::print; 移到 #include "FooInt.h" 之前，
//   print(5) 会改为调用 Foo::print(double) —— 这就是 using 语句依赖顺序的陷阱。
// 编译：g++ -std=c++20 -Wall 7-13-example7/main.cpp -o main
// 预期输出：Foo::print(int)

#include "FooDouble.h"
#include "FooInt.h"

using Foo::print; // print 现在表示 Foo::print

int main()
{
    print(5); // 调用 Foo::print(int)

    return 0;
}
