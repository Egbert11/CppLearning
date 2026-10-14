// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 7）
// 示例说明：用操纵器 std::hex / std::dec 切换进制；hex 一旦打开会持续生效。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   1b
//   1c
//   29
// 备注：原 Example 7 是片段，这里包进 main() 并补 <iostream>。代码逐字抽取。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << std::hex << 27 << '\n'; // print 27 in hex
    std::cout << 28 << '\n'; // we're still in hex
    std::cout << std::dec << 29 << '\n'; // back to decimal
    // --- 原文示例片段结束 ---

    return 0;
}
