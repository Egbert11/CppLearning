// ============================================================
// 来源小节：12.7 Introduction to pointers
// 示例说明：&x 会得到一个指针类型。用 typeid().name() 查看类型——
//           Visual Studio 打印 int / int *，gcc 打印 i / pi，含义相同
//           但具体字符串依编译器而异。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-pointers/
// 备注：本节代码为按原文描述忠实重建（原 Example 15）。
//       输出结果依编译器实现而定（gcc 通常为 i 与 pi）。
// ============================================================
#include <iostream>
#include <typeinfo>

int main()
{
    // --- 原文示例片段 ---
    int x{ 4 };
    std::cout << typeid(x).name() << '\n';  // print the type of x
    std::cout << typeid(&x).name() << '\n'; // print the type of &x
    // --- 原文示例片段结束 ---

    return 0;
}

// 预期输出（gcc，依编译器而异）：
// i
// Pi   （不同 gcc 版本可能是 "Pi" 或 "int*"，Visual Studio 为 int / int *）
