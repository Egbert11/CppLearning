// ============================================================
// 来源小节：5.2 Literals
// 示例说明：整数字面量的后缀（L -> long，u -> unsigned int）。
//           预期输出：5 5 5
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

int main()
{
    std::cout << 5 << '\n';  // 5 (no suffix) is type int (by default)
    std::cout << 5L << '\n'; // 5L is type long
    std::cout << 5u << '\n'; // 5u is type unsigned int

    return 0;
}
