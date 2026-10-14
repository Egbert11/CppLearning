// ============================================================
// 来源小节：17.10 C-style strings
// 示例说明：C 风格字符串不能先初始化、之后再整体赋值（原 Example 5）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-strings/
// 预期错误：str 是数组，数组不能整体赋值；
//           "invalid array assignment" / "assignment to expression with array type"。
//           此处用 -error 后缀表示预期编译失败，请勿"修复"。
// ============================================================
#include <iostream>

int main()
{
    char str[]{ "string" }; // ok
    str = "rope";           // not ok!  // compile error

    std::cout << str << '\n';

    return 0;
}
