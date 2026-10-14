// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 9）
// 示例说明：符号格式——标志 std::ios::showpos 与操纵器 showpos/noshowpos。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   5
//   +5
//   5
//   +5
// 备注：原 Example 9 是片段，这里包进 main() 并补 <iostream>。代码逐字抽取。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << 5 << '\n';

    std::cout.setf(std::ios::showpos);
    std::cout << 5 << '\n';

    std::cout << std::noshowpos << 5 << '\n';

    std::cout << std::showpos << 5 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
