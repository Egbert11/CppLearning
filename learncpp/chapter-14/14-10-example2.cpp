// ============================================================
// 来源小节：14.10 Constructor member initializer lists
// 示例说明：初始化列表的排版自由——冒号、逗号、空白可任意安排，三种写法等价。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
// 备注：本节代码为按原文描述忠实重建。原文给出的是三份"构造函数头部"片段，
//       这里只保留一份可编译的类，其余两种排发放进注释对照。
// ============================================================
#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    // 原文 Example 2 之写法一：全部挤在一行
    // Foo(int x, int y) : m_x { x }, m_y { y }
    // {
    // }

    // 原文 Example 2 之写法二：冒号换行，逗号在行尾
    // Foo(int x, int y) :
    //     m_x { x },
    //     m_y { y }
    // {
    // }

    // 原文 Example 3（本节采用的推荐写法）：冒号换行，逗号在行首，保持对齐
    Foo(int x, int y)
        : m_x { x }
        , m_y { y }
    {
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
// Foo(6, 7)
