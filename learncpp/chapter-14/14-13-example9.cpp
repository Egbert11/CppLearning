// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：不能用拷贝初始化创建临时对象（无此语法）；直接初始化可以：
//           Foo (1, 2); 行为类似 Foo { 1, 2 }，但不阻止窄化转换。
//           它看起来像函数调用，其实不是。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

class Foo
{
private:
    int m_a{};
    int m_b{};

public:
    Foo(int a, int b)
        : m_a{ a }, m_b{ b }
    {
    }

    int a() const { return m_a; }
    int b() const { return m_b; }
};

int main()
{
    // --- 原文示例片段（原 Example 10）---
    Foo (1, 2); // temporary Foo, direct-initialized with (1, 2)
    // --- 原文示例片段结束 ---

    // 上面创建的是一个临时 Foo（不是函数调用）。
    std::cout << Foo (1, 2).a() << '\n'; // 1

    return 0;
}
