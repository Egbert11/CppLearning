// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 5）
// 示例说明：变通方法 1——先 unsetf(std::ios::dec) 关掉十进制，
//           再 setf(std::ios::hex) 打开十六进制。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   1b
// 备注：原 Example 5 是片段，这里包进 main() 并补 <iostream>。代码逐字抽取。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout.unsetf(std::ios::dec); // turn off decimal output
    std::cout.setf(std::ios::hex); // turn on hexadecimal output
    std::cout << 27 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
