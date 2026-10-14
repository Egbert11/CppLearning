// ============================================================
// 来源小节：12.3 Lvalue references
// 示例说明：通过非 const 左值引用修改被引用对象的值——引用与它引用的
//           对象本质上是同一个东西。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references/
// 备注：本节代码为按原文描述忠实重建（原 Example 3）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    int x { 5 };    // normal integer variable
    int& ref { x }; // ref is now an alias for variable x

    std::cout << x << ref << '\n'; // print 55

    x = 6; // x now has value 6

    std::cout << x << ref << '\n'; // prints 66

    ref = 7; // the object being referenced (x) now has value 7

    std::cout << x << ref << '\n'; // prints 77
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 55
// 66
// 77
