// ============================================================
// 来源小节：12.6 Pass by const lvalue reference
// 示例说明：const 引用形参不能被修改——按 const 引用传递保证函数不会
//           改动被引用值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/
// !! -error：预期编译失败，勿修复。
//   预期错误：increment of read-only reference 'ref'（函数体内的 ++ref）。
// 备注：本节代码为按原文描述忠实重建（原 Example 2）。
// ============================================================
void addOne(const int& ref)
{
    ++ref; // not allowed: ref is const
}

int main()
{
    int x { 5 };
    addOne(x); // the error is inside addOne

    return 0;
}
