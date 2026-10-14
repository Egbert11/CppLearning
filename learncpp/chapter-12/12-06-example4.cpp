// ============================================================
// 来源小节：12.6 Pass by const lvalue reference
// 示例说明：一个函数可对每个形参独立决定传递方式——这里分别是按值、
//           按非 const 引用、按 const 引用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 4）。
// ============================================================
#include <string>

void foo(int a, int& b, const std::string& c)
{
    // a passed by value, b passed by reference, c passed by const reference
    (void)a;
    (void)b;
    (void)c;
}

int main()
{
    int x { 5 };
    const std::string s { "Hello, world!" };

    foo(5, x, s);

    return 0;
}
