// ============================================================
// 来源小节：13.14 Class template argument deduction (CTAD) and deduction guides
// 示例说明：非静态成员初始化中不能使用 CTAD。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-template-argument-deduction-ctad-and-deduction-guides/
// 预期错误：error: class template placeholder 'std::pair' not permitted in this context
//           （std::pair p2{ 1, 2 }; 处）
// 备注：本节代码为按原文描述忠实重建。故意编译失败，请勿修复。main 中的 p3 合法。
// ============================================================
#include <utility> // for std::pair

struct Foo
{
    // --- 原文示例片段（原 Example 9）---
    std::pair<int, int> p1{ 1, 2 }; // ok, template arguments explicitly specified
    std::pair p2{ 1, 2 };           // compile error, CTAD can't be used in this context
};

int main()
{
    std::pair p3{ 1, 2 };           // ok, CTAD can be used here
    return 0;
}
