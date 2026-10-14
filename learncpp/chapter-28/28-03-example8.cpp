// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 8）
// 示例说明：布尔格式——标志 std::ios::boolalpha 与操纵器 boolalpha/noboolalpha。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   1 0
//   true false
//   1 0
//   true false
// 备注：原 Example 8 是片段，这里包进 main() 并补 <iostream>。代码逐字抽取。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << true << ' ' << false << '\n';

    std::cout.setf(std::ios::boolalpha);
    std::cout << true << ' ' << false << '\n';

    std::cout << std::noboolalpha << true << ' ' << false << '\n';

    std::cout << std::boolalpha << true << ' ' << false << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
