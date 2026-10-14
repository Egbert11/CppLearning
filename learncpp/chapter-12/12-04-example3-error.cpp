// ============================================================
// 来源小节：12.4 Lvalue references to const
// 示例说明：通过 const 引用可以读取对象，但不能写入（修改）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
// !! -error：预期编译失败，勿修复。
//   预期错误：assignment of read-only reference 'ref'（ref = 6 一行）。
// 备注：本节代码为按原文描述忠实重建（原 Example 3）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    const int x { 5 };    // x is a non-modifiable lvalue
    const int& ref { x }; // okay: ref is an lvalue reference to a const value

    std::cout << ref << '\n'; // okay: we can access the const object
    ref = 6;                  // error: we can not modify an object through a const reference
    // --- 原文示例片段结束 ---

    return 0;
}
