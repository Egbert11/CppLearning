// ============================================================
// 来源小节：14.9 Introduction to constructors
// 示例说明：构造函数必须是非 const（它要修改正在构造的对象）。
//           这里 Something() 在体内把 m_x 设为 5；即便对象声明为 const，
//           隐式调用的仍是这个非 const 构造函数，之后 const 才生效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-constructors/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 6）---
class Something
{
private:
    int m_x{};

public:
    Something() // constructors must be non-const
    {
        m_x = 5; // okay: we can assign to m_x
    }

    int getX() const { return m_x; }
};

int main()
{
    const Something s{}; // const doesn't apply during construction; the (non-const) ctor runs
    std::cout << s.getX();

    return 0;
}

// 预期输出：
// 5
