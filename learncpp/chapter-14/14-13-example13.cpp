// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：static_cast<int>(c) 产生一个由 c 直接初始化的临时 int；
//           int { c } 产生一个由 c 列表初始化的临时 int。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段（原 Example 15）---
    char c { 'a' };

    std::cout << static_cast<int>( c ) << '\n'; // static_cast creates a temporary int
    std::cout << int { c } << '\n';             // list-initialized temporary int
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出：
// 97
// 97
