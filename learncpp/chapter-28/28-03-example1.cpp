// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 1）
// 示例说明：用 setf() 打开 std::ios::showpos 标志，让正数带前导 '+'。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   +27
// 备注：原 Example 1 是片段，这里包进 main() 并补 <iostream>。代码逐字抽取。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout.setf(std::ios::showpos); // turn on the std::ios::showpos flag
    std::cout << 27 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
