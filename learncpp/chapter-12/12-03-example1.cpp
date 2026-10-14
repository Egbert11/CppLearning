// ============================================================
// 来源小节：12.3 Lvalue references
// 示例说明：对比普通类型与引用类型的写法；左值引用类型在类型说明符
//           里用一个 & 标识。因为这些只是"类型片段"而非可执行语句，
//           原文片段以注释保留，另加一段可编译的演示。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references/
// 备注：本节代码为按原文描述忠实重建（原 Example 1）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（类型语法，非可执行语句）---
    // regular types
    // int        // a normal int type (not a reference)
    // int&       // an lvalue reference to an int object
    // double&    // an lvalue reference to a double object
    // const int& // an lvalue reference to a const int object
    // --- 原文示例片段结束 ---

    int x { 5 };
    int& ref { x }; // an lvalue reference to an int object

    std::cout << ref << '\n';

    return 0;
}

// 预期输出：
// 5
