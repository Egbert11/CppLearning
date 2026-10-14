// ============================================================
// 来源小节：14.15 Class initialization and copy elision
// 示例说明：不必要的拷贝——Something s { Something { 5 } }; 先构造临时对象，
//           再拷贝构造 s；更好的写法 Something s { 5 }; 只调用 Something(int)。
//           C++17 下拷贝被强制消除，输出只剩 Normal constructor 与 Something(5)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-initialization-and-copy-elision/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

class Something
{
private:
    int m_x{};

public:
    Something(int x)
        : m_x{ x }
    {
        std::cout << "Normal constructor\n";
    }

    Something(const Something& s)
        : m_x { s.m_x }
    {
        std::cout << "Copy constructor\n";
    }

    void print() const { std::cout << "Something(" << m_x << ")\n"; }
};

int main()
{
    // --- 原文示例片段（原 Example 3）---
    Something s { Something { 5 } }; // focus on this line
    s.print();

    // efficient alternative:
    // Something s { 5 }; // only invokes Something(int), no copy constructor
    // --- 原文示例片段结束 ---

    return 0;
}

// 未优化时的预期输出：
// Normal constructor
// Copy constructor
// Something(5)
//
// C++17 起，拷贝被强制消除，预期输出为：
// Normal constructor
// Something(5)
