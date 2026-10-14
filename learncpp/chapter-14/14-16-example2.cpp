// ============================================================
// 来源小节：14.16 Converting constructors and the explicit keyword
// 示例说明：类类型参数通过 Foo(int) 隐式转换——printFoo 形参是 Foo，传入 int 5
//           时编译器用 Foo(int) 把 5 转换为 Foo。Foo(int) 即"转换构造函数"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 2）---
class Foo
{
private:
    int m_x{};
public:
    Foo(int x)
        : m_x{ x }
    {
    }

    int getX() const { return m_x; }
};

void printFoo(Foo f) // has a Foo parameter
{
    std::cout << f.getX();
}

int main()
{
    printFoo(5); // we're supplying an int argument

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// 5
