// ============================================================
// 来源小节：14.9 Introduction to constructors
// 示例说明：把成员设为 private 后类型不再是非聚合体，聚合初始化无法编译。
//           请勿修复此文件。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-constructors/
// 预期错误：g++ 报错类似
//   "error: no matching function for call to 'Foo::Foo(<brace-enclosed initializer list>)'"
//   （private 成员使 Foo 不再是聚合体，且没有匹配的构造函数）。
// 备注：本节代码为按原文描述忠实重建。此文件故意编译失败。
// ============================================================
// --- 原文示例片段（原 Example 2）---
class Foo
{
private:
    int m_x {};
    int m_y {};
};

int main()
{
    Foo foo { 6, 7 }; // compile error: can not use aggregate initialization

    return 0;
}
