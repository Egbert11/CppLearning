// ============================================================
// 来源小节：5.2 Literals
// 示例说明：浮点字面量的后缀（f -> float）。预期输出：5 5
// 原文链接：https://www.learncpp.com/cpp-tutorial/literals/
// ============================================================
#include <iostream>

int main()
{
    std::cout << 5.0 << '\n';  // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f << '\n'; // 5.0f is type float

    return 0;
}
