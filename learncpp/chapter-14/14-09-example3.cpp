// ============================================================
// 来源小节：14.9 Introduction to constructors
// 示例说明：为 Foo 定义 Foo(int, int) 构造函数。构造函数体只打印，
//           并未初始化 m_x/m_y（它们由默认成员初始化器 {} 变为 0），故打印 Foo(0, 0)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-constructors/
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
    Foo(int x, int y) // constructor
    {
        // the constructor body only prints; it never initializes m_x/m_y
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 }; // calls Foo(int, int) constructor
    foo.print();

    return 0;
}

// 预期输出：
// Foo(6, 7) constructed
// Foo(0, 0)
