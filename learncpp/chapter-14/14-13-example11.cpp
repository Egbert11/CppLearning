// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：单参数的不一致之处——Foo(1); 是函数式转换，返回一个临时 Foo；
//           而 Foo(bar); 却是定义一个名为 bar 的变量（等价 Foo bar;），
//           与 Foo { bar }、Foo(1) 的形式不一致。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

class Foo
{
private:
    int m_x{};

public:
    Foo(int x)
        : m_x{ x }
    {
    }

    int x() const { return m_x; }
};

int main()
{
    // --- 原文示例片段（原 Example 12）---
    Foo(1); // function-style cast: temporary Foo, direct-initialized with 1
    // Foo(bar); // defines a variable named bar of type Foo (like Foo bar;)
    // --- 原文示例片段结束 ---

    std::cout << Foo(1).x() << '\n'; // 1

    return 0;
}
