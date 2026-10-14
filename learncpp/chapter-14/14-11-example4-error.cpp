// ============================================================
// 来源小节：14.11 Default constructors and default arguments
// 示例说明：两个都能无参调用的“默认构造函数”同时存在时，foo{} 无法抉择——
//           预期编译失败。请勿修复此文件。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/
// 预期错误：g++ 报错类似
//   "error: call of overloaded 'Foo()' is ambiguous"
// 备注：本节代码为按原文描述忠实重建。此文件故意编译失败。
// ============================================================
// --- 原文示例片段（原 Example 5）---
class Foo
{
public:
    Foo()
    {
    }

    Foo(int x=1, int y=2) // all parameters have default arguments -> also a default constructor
    {
    }
};

int main()
{
    Foo foo{}; // ambiguous constructor function call

    return 0;
}
