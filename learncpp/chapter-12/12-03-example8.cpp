// ============================================================
// 来源小节：12.3 Lvalue references
// 示例说明：引用变量与普通变量一样遵循作用域/生存期规则。引用先于其
//           被引用对象销毁时，被引用对象不受影响（引用和被引用对象的
//           生存期彼此独立，下一节的例外除外）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references/
// 备注：本节代码为按原文描述忠实重建（合并原 Example 8 与 Example 9）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（原 Example 8）---
    int x { 5 };    // normal integer
    int& ref { x }; // reference to variable x
    // --- 原文示例片段结束 ---

    (void)ref;

    {
        // --- 原文示例片段（原 Example 9）---
        int& inner { x };         // inner is a reference to x
        std::cout << inner << '\n'; // prints value of inner (5)
        // --- 原文示例片段结束 ---
    } // inner is destroyed here -- x is unaware of this

    std::cout << x << '\n'; // prints value of x (5)

    return 0;
} // x and ref destroyed here

// 预期输出：
// 5
// 5
