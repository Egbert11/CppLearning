// ============================================================
// 来源小节：14.16 Converting constructors and the explicit keyword
// 示例说明：返回值的隐式转换在构造函数为 explicit 时失败——return { };、
//           return 5;、return { 5 }; 都试图隐式转换，故编译错误。
//           本文件对应原 Example 12 中 error 的部分。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
// 备注：本节代码为按原文描述忠实重建。
//
// *** 本文件为预期编译失败示例（-error），请勿"修复" ***
// 预期错误：return { }; 处——无法把初始化列表隐式转换为 Foo
//           （could not convert '{ }' from '<brace-enclosed initializer list>' to 'Foo'）。
//           取消下方注释还会触发 return 5; 与 return { 5 }; 的同类错误。
// ============================================================
class Foo
{
public:
    explicit Foo()
    {
    }

    explicit Foo(int x)
    {
    }
};

Foo getFoo()
{
    // --- 原文示例片段（原 Example 12，error 部分）---
    // explicit Foo() cases
    return { };      // error: can't implicitly convert initializer list to Foo

    // explicit Foo(int) cases
    // return 5;     // error: can't implicitly convert int to Foo
    // return { 5 }; // error: can't implicitly convert initializer list to Foo
    // --- 原文示例片段结束 ---
}

int main()
{
    return 0;
}
