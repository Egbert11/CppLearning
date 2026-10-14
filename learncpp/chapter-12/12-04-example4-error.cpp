// ============================================================
// 来源小节：12.4 Lvalue references to const
// 示例说明：const 引用可以绑定可修改左值；此时透过引用看到的是 const，
//           但仍可通过原本的标识符 x 修改它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
// !! -error：预期编译失败，勿修复。
//   预期错误：assignment of read-only reference 'ref'（ref = 7 一行）。
// 备注：本节代码为按原文描述忠实重建（原 Example 4）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };          // x is a modifiable lvalue
    const int& ref { x }; // okay: we can bind a const reference to a modifiable lvalue

    std::cout << ref << '\n'; // okay: we can access the object through our const reference
    ref = 7;                  // error: we can not modify an object through a const reference

    x = 6;                // okay: x is a modifiable lvalue, we can still modify it through the original identifier
    // --- 原文示例片段结束 ---

    return 0;
}
