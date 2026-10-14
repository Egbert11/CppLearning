// ============================================================
// 来源小节：12.3 Lvalue references
// 示例说明：创建左值引用变量并通过它读取被引用对象的值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references/
// 备注：本节代码为按原文描述忠实重建（原 Example 2）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };    // x is a normal integer variable
    int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x

    std::cout << x << '\n';   // print the value of x (5)
    std::cout << ref << '\n'; // print the value of x via ref (5)
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 5
// 5
