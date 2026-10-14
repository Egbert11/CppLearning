// ============================================================
// 来源小节：6.6 The conditional operator
// 示例说明：操作数类型匹配、可转换以及有符号/无符号混用的意外结果。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-conditional-operator/
// 备注：本节代码为按原文描述忠实重建。
//   假设 4 字节 int，输出：1 / 2.2 / 4294967295
//   （4294967295 即 -1 转成 unsigned int 的结果，依 int 宽度而定）
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << (true ? 1 : 2) << '\n';    // 1     (both int)
    std::cout << (false ? 1 : 2.2) << '\n'; // 2.2   (int 1 converted to double)
    std::cout << (true ? -1 : 2u) << '\n';  // 4294967295 (int -1 converted to unsigned int)
    // --- 原文示例片段结束 ---

    return 0;
}
