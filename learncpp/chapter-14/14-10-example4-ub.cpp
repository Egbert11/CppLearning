// ============================================================
// 来源小节：14.10 Constructor member initializer lists
// 示例说明：三种初始化方式的优先级——初始化列表 > 默认成员初始化器 > 默认初始化。
//           m_x 取列表里的 6；m_y 用默认值 2；m_z 无任何初始化器，保持未初始化。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/
// 备注：本节代码为按原文描述忠实重建。打印未初始化的 m_z 是未定义行为，
//       作者机器上输出 -858993460，实际值依实现而定，切勿依赖。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 5）---
class Foo
{
private:
    int m_x {};    // default member initializer (will be ignored)
    int m_y { 2 }; // default member initializer (will be used)
    int m_z;      // no initializer

public:
    Foo(int x)
        : m_x { x } // member initializer list
    {
        std::cout << "Foo constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }
};

int main()
{
    Foo foo { 6 };
    foo.print();

    return 0;
}

// 预期输出（作者机器上；m_z 部分为未定义行为，依实现而定）：
// Foo constructed
// Foo(6, 2, -858993460)
