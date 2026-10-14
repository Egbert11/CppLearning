// ============================================================
// 来源小节：17.11 C-style string symbolic constants
// 示例说明：用字符串字面量初始化 char 数组，得到一个可读的 C 风格字符串（原 Example 1）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants/
// 预期输出：Alex
// ============================================================
#include <iostream>

int main()
{
    char name[]{ "Alex" }; // C-style string
    std::cout << name << '\n';

    return 0;
}
