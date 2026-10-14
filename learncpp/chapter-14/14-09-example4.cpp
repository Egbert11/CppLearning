// ============================================================
// 来源小节：14.9 Introduction to constructors
// 示例说明：对照示例——普通函数也能做隐式转换，'a'（char）与 true（bool）
//           被隐式转换为 int，因而匹配 foo(int, int)。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-constructors/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
// --- 原文示例片段（原 Example 4）---
void foo(int, int)
{
}

int main()
{
    foo('a', true); // will match foo(int, int)

    return 0;
}

// 预期输出：无（仅演示经由隐式转换完成的重载匹配）
