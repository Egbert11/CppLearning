// ============================================================
// 来源小节：14.10 Constructor member initializer lists
// 示例说明：在构造函数体内给成员赋值是“赋值”而非“初始化”。
//           对本例的 int 成员结果看似正确，但对 const 或引用成员会编译失败，
//           因此应使用成员初始化列表。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
// 备注：本节代码为按原文描述忠实重建（原文给出完整代码）。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 6）---
class Foo
{
private:
    int m_x { 0 };
    int m_y { 1 };

public:
    Foo(int x, int y)
    {
        m_x = x; // incorrect: this is an assignment, not an initialization
        m_y = y; // incorrect: this is an assignment, not an initialization
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo { 6, 7 };
    foo.print();

    return 0;
}

// 预期输出：
// Foo(6, 7)
