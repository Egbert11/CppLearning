// 来源小节：4.11 Chars
// 示例说明：警告演示——整数 5 与字符 '5' 并不相同（'5' 存为 53）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chars/
// 注意：原文用同一个变量名 ch 分两行演示，这里改用 ch1/ch2 以便编译。

#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    char ch1{ 5 };   // initialize with integer 5 (stored as integer 5)
    char ch2{ '5' }; // initialize with code point for '5' (stored as integer 53, not 5!)
    // --- 原文示例片段 ---

    std::cout << "ch1 (as int) = " << static_cast<int>(ch1) << '\n'; // 5
    std::cout << "ch2 (as int) = " << static_cast<int>(ch2) << '\n'; // 53

    return 0;
}
