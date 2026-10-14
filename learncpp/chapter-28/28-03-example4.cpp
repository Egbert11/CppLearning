// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 4）
// 示例说明：只用 setf(std::ios::hex) 想把输出切到十六进制会失败——
//           因为 setf() 不会清掉同组里已激活的默认 dec 标志。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   27        // 仍是十进制！
// 备注：原 Example 4 是片段，这里包进 main() 并补 <iostream>。代码逐字抽取。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout.setf(std::ios::hex); // try to turn on hex output
    std::cout << 27 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
