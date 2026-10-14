// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：创建临时类对象的两种常见方式——显式写出类型 IntPair { 5, 6 }，
//           或让编译器由形参推导并隐式转换花括号列表 { 7, 8 }。
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

int main()
{
    // --- 原文示例片段（原 Example 7）---
    // Case 1: Pass variable
    IntPair p { 3, 4 };
    print(p);

    // Case 2: Construct temporary IntPair and pass to function
    print(IntPair { 5, 6 } );

    // Case 3: Implicitly convert { 7, 8 } to a temporary IntPair and pass
    print( { 7, 8 } );
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// (3, 4)
// (5, 6)
// (7, 8)
