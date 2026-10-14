// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：IntPair 类 + print(IntPair) —— 情况 1：先创建具名对象 p，
//           再把 p 传给函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 6）---
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

int main()
{
    // Case 1: Pass variable
    IntPair p { 3, 4 };
    print(p);

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// (3, 4)
