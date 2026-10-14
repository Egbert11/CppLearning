// ============================================================
// 来源小节：12.3 Lvalue references
// 示例说明：引用一经初始化便无法"重新指向"（reseat）。ref = y 看上去
//           像让 ref 改指 y，实际是把 y 的值赋给了 ref 所引用的 x。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references/
// 备注：本节代码为按原文描述忠实重建（原 Example 7）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };
    int y { 6 };

    int& ref { x }; // ref is now an alias for x

    ref = y; // assigns 6 (the value of y) to x (the object being referenced by ref)
    // The above line does NOT change ref into a reference to variable y!

    std::cout << x << '\n'; // user is expecting this to print 5
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 6
