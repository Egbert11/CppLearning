// 来源小节：1.4 Variable assignment and initialization
// 示例说明：在一条语句里完成"定义 + 初始化"，并列出五种常见的初始化形式。
// 原文链接：https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
//
// 预期输出（为便于观察，本示例把已初始化的变量打印出来）：
//   5
//   5 6 7 0
//
// 注意：变量 a 采用默认初始化（无初始化器），其值是不确定的，读取它是未定义行为，
// 因此本示例不打印 a（它也会触发 g++ -Wall 的 unused variable 警告）。

#include <iostream>

int main()
{
    // --- 原文示例片段：一条语句完成定义与初始化 ---
    int width { 5 };    // define variable width and initialize with initial value 5
    std::cout << width; // prints 5
    std::cout << '\n';
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：五种常见的初始化形式 ---
    int a;         // default-initialization (no initializer)

    // Traditional initialization forms:
    int b = 5;     // copy-initialization (initial value after equals sign)
    int c ( 6 );   // direct-initialization (initial value in parenthesis)

    // Modern initialization forms (preferred):
    int d { 7 };   // direct-list-initialization (initial value in braces)
    int e {};      // value-initialization (empty braces)
    // --- 原文示例片段结束 ---

    // 为使用 b/c/d/e、避免未使用变量警告而打印它们（a 故意不打印）
    std::cout << b << ' ' << c << ' ' << d << ' ' << e << '\n';

    return 0;
}
