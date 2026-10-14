// 来源小节：7.13 Using declarations and using directives
// 示例说明：静默的行为变化。最初库只提供 Foo::get(long)；later 库新增 Foo::get(int)，
//           由于字面量 0 是 int、与 get(int) 精确匹配，get(0) 的调用被静默改到新函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/
//
// 本节示例为按原文描述重建（对应原文 Example 9）。
// 预期输出：2（若库尚未新增 get(int)，则本应输出 1 —— 这就是"行为静默改变"）

#include <iostream>

namespace Foo
{
    int get(long) { return 1; }
}

using namespace Foo; // 导入 Foo 中的名字（包括 get）

namespace Foo
{
    // 库后来新增的重载：对字面量 0（int）而言，它比 get(long) 更匹配
    int get(int) { return 2; }
}

int main()
{
    std::cout << get(0) << '\n'; // 输出 2（而非 1）：行为被静默改变

    return 0;
}
