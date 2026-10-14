// ============================================================
// 来源小节：14.10 Constructor member initializer lists
// 示例说明：成员始终按“声明顺序”而非“列表书写顺序”初始化。
//           这里 m_x 声明在前，虽在列表中写在 m_y 之后，仍先初始化 m_x { m_y }，
//           而此时 m_y 尚未初始化，于是 m_x 取值不确定（未定义行为）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
// 备注：本节代码为按原文描述忠实重建。读取未初始化的 m_y 是未定义行为，
//       作者机器上输出 Foo(-858993460, 7)，实际值依实现而定，切勿依赖；
//       可用 -Wuninitialized 或 -fsanitize=address 观察。
// ============================================================
#include <algorithm> // for std::max
#include <iostream>

// --- 原文示例片段（原 Example 4）---
class Foo
{
private:
    int m_x{};
    int m_y{};

public:
    Foo(int x, int y)
        : m_y { std::max(x, y) }, m_x { m_y } // issue on this line
    {
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

// 预期输出（作者机器上；m_x 部分为未定义行为，依实现而定）：
// Foo(-858993460, 7)
