// 来源小节：7.13 Using declarations and using directives
// 示例说明：一条 using 语句一旦声明就无法在其作用域内取消/替换；最多用嵌套块限制其作用域，
//           每个 using 指令在所在块的末尾即失效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/
//
// 本节示例为按原文描述重建（对应原文 Example 14）。
// 预期输出：
// Foo::foo
// Goo::goo

#include <iostream>

namespace Foo
{
    void foo() { std::cout << "Foo::foo\n"; }
}

namespace Goo
{
    void goo() { std::cout << "Goo::goo\n"; }
}

int main()
{
    {
        using namespace Foo;
        foo(); // 调用 Foo::foo
    } // using namespace Foo 在此失效

    {
        using namespace Goo;
        goo(); // 调用 Goo::goo
    } // using namespace Goo 在此失效

    return 0;
}
