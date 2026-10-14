// 来源小节：1.4 Variable assignment and initialization
// 示例说明：在一行里定义多个变量、在一行里初始化多个变量，以及 int a, b = 5; 的陷阱。
// 原文链接：https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
//
// 说明：定义但未初始化/未使用的变量会触发 g++ -Wall 的警告，这符合本节示例本意。

int main()
{
    // --- 原文示例片段：定义多个变量但不初始化 ---
    int a, b; // create variables a and b, but do not initialize them
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：在同一行初始化多个变量 ---
    int c = 5, d = 6;      // copy-initialization
    int e ( 7 ), f ( 8 );  // direct-initialization
    int g { 9 }, h { 10 }; // direct-list-initialization
    int i {}, j {};        // value-initialization
    // --- 原文示例片段结束 ---

    // --- 原文示例片段：多变量同行的常见陷阱 ---
    // int k, m = 5;     // wrong: k is not initialized to 5!
    int k = 5, m = 5;    // correct: k and m are initialized to 5
    // --- 原文示例片段结束 ---

    return 0;
}
