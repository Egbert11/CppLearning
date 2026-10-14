// ============================================================
// 来源小节：12.4 Lvalue references to const
// 示例说明：const 引用可绑定到类型不同、但能隐式转换的值——编译器创建
//           引用类型的临时对象，用该值初始化它，再让引用绑定它。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
// 备注：本节代码为按原文描述忠实重建（原 Example 6）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    // case 1
    const double& r1 { 5 };  // temporary double initialized with value 5, r1 binds to temporary

    std::cout << r1 << '\n'; // prints 5

    // case 2
    char c { 'a' };
    const int& r2 { c };     // temporary int initialized with value 'a', r2 binds to temporary

    std::cout << r2 << '\n'; // prints 97 (since r2 is a reference to int)
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 5
// 97
