// ============================================================
// 来源小节：17.10 C-style strings
// 示例说明：因为 C 风格字符串本质是数组，可用 [] 修改单个字符（原 Example 6）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-strings/
// 预期输出：
//   string
//   spring
// ============================================================
#include <iostream>

int main()
{
    char str[]{ "string" };
    std::cout << str << '\n';
    str[1] = 'p';
    std::cout << str << '\n';

    return 0;
}
