// ============================================================
// 来源小节：14.11 Default constructors and default arguments
// 示例说明：形参全部带默认值（=0）的构造函数也是默认构造函数，
//           既可无参调用，也可带实参调用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 3）---
class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x=0, int y=0)
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
};

int main()
{
    Foo foo1{};    // calls Foo(0, 0) via the default arguments
    Foo foo2{6, 7};

    return 0;
}

// 预期输出：
// Foo(0, 0) constructed
// Foo(6, 7) constructed
