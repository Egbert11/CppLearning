// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：按值返回会产生临时对象——返回具名局部变量、返回显式临时对象、
//           返回被隐式转换的花括号列表，三种情形都生成临时对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

class IntPair
{
private:
    int m_x{};
    int m_y{};

public:
    IntPair(int x, int y)
        : m_x{ x }, m_y{ y }
    {
    }

    int x() const { return m_x; }
    int y() const { return m_y; }
};

void print(IntPair p)
{
    std::cout << '(' << p.x() << ", " << p.y() << ")\n";
}

// --- 原文示例片段（原 Example 14）---
// Case 1: Return by value (returns a temporary object initialized with local p)
IntPair ret1()
{
    IntPair p { 1, 2 };
    return p;
}

// Case 2: Return temporary object
IntPair ret2()
{
    return IntPair { 3, 4 };
}

// Case 3: Implicitly convert { 5, 6 } to a temporary object
IntPair ret3()
{
    return { 5, 6 };
}

int main()
{
    print(ret1());
    print(ret2());
    print(ret3());

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// (1, 2)
// (3, 4)
// (5, 6)
