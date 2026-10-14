// ============================================================
// 来源小节：17.11 C-style string symbolic constants
// 示例说明：C 风格字符串符号常量的两种写法——const 数组 与 const 指针（原 Example 2）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/c-style-string-symbolic-constants/
// 预期输出：Alex Orange
// 备注：两者结果看起来相同，但内存处理略有不同（见 md 中"核心概念"）。
// ============================================================
#include <iostream>

int main()
{
    const char name[] { "Alex" };        // case 1: const C-style array
    const char* const color{ "Orange" }; // case 2: const pointer to a C-style string literal

    std::cout << name << ' ' << color << '\n';

    return 0;
}
