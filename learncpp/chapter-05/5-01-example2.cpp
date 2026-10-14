// ============================================================
// 来源小节：5.1 Constant variables (named constants)
// 示例说明：演示 const 限定符写在类型前（推荐）与写在类型后
//           （"east const"）两种等价写法。
// 原文链接：https://www.learncpp.com/cpp-tutorial/constant-variables-named-constants/
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    const double gravity { 9.8 };  // preferred use of const before type
    int const sidesInSquare { 4 }; // "east const" style, works, but not preferred
    // --- 原文示例片段结束 ---

    // gravity 的类型是 const double；sidesInSquare 的类型是 const int
    std::cout << gravity << '\n';
    std::cout << sidesInSquare << '\n';

    return 0;
}
