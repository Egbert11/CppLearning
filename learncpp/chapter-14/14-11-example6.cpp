// ============================================================
// 来源小节：14.11 Default constructors and default arguments
// 示例说明：类已有用户声明的 Foo(int, int) 时，用 Foo() = default 显式默认化一个
//           默认构造函数，使 foo{} 仍可编译。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 8）---
class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo() = default; // explicitly defaulted default constructor

    Foo(int x, int y)
        : m_x { x }, m_y { y }
    {
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{}; // uses the explicitly defaulted default constructor
    foo.print();

    return 0;
}

// 预期输出：
// Foo(0, 0)
