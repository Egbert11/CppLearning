// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 10）
// 示例说明：大小写格式——标志 std::ios::uppercase 影响科学计数法的 'E'。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   1.23457e+007
//   1.23457E+007
//   1.23457e+007
//   1.23457E+007
// 备注：原 Example 10 是片段，这里包进 main() 并补 <iostream>。代码逐字抽取。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << 12345678.9 << '\n';

    std::cout.setf(std::ios::uppercase);
    std::cout << 12345678.9 << '\n';

    std::cout << std::nouppercase << 12345678.9 << '\n';

    std::cout << std::uppercase << 12345678.9 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
