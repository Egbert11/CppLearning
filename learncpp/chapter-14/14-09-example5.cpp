// ============================================================
// 来源小节：14.9 Introduction to constructors
// 示例说明：构造函数与普通函数一样接受隐式转换——'a' 与 true 被转换为 int，
//           匹配 Foo(int, int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-constructors/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
// --- 原文示例片段（原 Example 5）---
class Foo
{
public:
    Foo(int x, int y)
    {
    }
};

int main()
{
    Foo foo{ 'a', true }; // will match Foo(int, int) constructor

    return 0;
}

// 预期输出：无（仅演示经由隐式转换完成的重载匹配）
