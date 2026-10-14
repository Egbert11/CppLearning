// ============================================================
// 来源小节：12.4 Lvalue references to const
// 示例说明：const 左值引用可以绑定右值——会创建一个以该右值初始化的
//           临时对象，引用绑定到这个临时对象。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
// 备注：本节代码为按原文描述忠实重建（原 Example 5）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    const int& ref { 5 }; // okay: 5 is an rvalue

    std::cout << ref << '\n'; // prints 5
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 5
