// ============================================================
// 来源小节：14.10 Constructor member initializer lists
// 示例说明：用成员初始化列表直接初始化 m_x、m_y，随后构造函数体才打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
// 备注：本节代码为按原文描述忠实重建（原文给出完整代码）。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 1）---
class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y)
        : m_x { x }, m_y { y } // here's our member initialization list
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 };
    foo.print();

    return 0;
}

// 预期输出：
// Foo(6, 7) constructed
// Foo(6, 7)
