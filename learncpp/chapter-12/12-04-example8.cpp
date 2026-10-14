// ============================================================
// 来源小节：12.4 Lvalue references to const
// 示例说明：生存期延长——临时对象通常在创建它的表达式结束时就销毁，
//           但当 const 左值引用"直接"绑定到临时对象时，该临时对象的
//           生存期被延长到与引用一致，从而避免悬垂引用。
// 原文链接：https://www.learncpp.com/cpp-tutorial/lvalue-references-to-const/
// 备注：本节代码为按原文描述忠实重建（原 Example 8）。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    const int& ref { 5 }; // The temporary object holding value 5 has its lifetime extended to match ref

    std::cout << ref << '\n'; // Therefore, we can safely use it here
    // --- 原文示例片段结束 ---

    return 0;
} // Both ref and the temporary object die here

// 预期输出：
// 5
