// ============================================================
// 来源小节：14.11 Default constructors and default arguments
// 示例说明：重载构造函数——一个无参的 Foo() 与一个 Foo(int, int)，
//           分别由 foo1{} 与 foo2{6, 7} 匹配。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 4）---
class Foo
{
public:
    Foo()
    {
        std::cout << "Foo constructed\n";
    }

    Foo(int x, int y)
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }
};

int main()
{
    Foo foo1{};    // calls Foo()
    Foo foo2{6, 7}; // calls Foo(int, int)

    return 0;
}

// 预期输出：
// Foo constructed
// Foo(6, 7) constructed
