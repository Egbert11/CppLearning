// 来源小节：20.x Chapter 20 summary and quiz（Quiz 2a）
// 示例说明：函数返回了局部数组元素的引用；数组在函数结束时被销毁，
//           返回的引用成为悬垂引用（之后使用是未定义行为）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-20-summary-and-quiz/
// 说明：本节代码为按原文描述重建。
// 预期警告：warning: reference to local variable 'array' returned [-Wreturn-local-addr]
// 请勿修复：此文件用于演示"返回悬垂引用"这个错误。

// --- 原文示例片段 ---
int& doSomething()
{
    int array[]{ 1, 2, 3, 4, 5 };
    return array[3]; // returns a reference to a local that is destroyed on return
}
// --- 原文示例片段结束 ---

int main()
{
    // Not calling doSomething() to avoid triggering the undefined behavior at runtime.
    return 0;
}
