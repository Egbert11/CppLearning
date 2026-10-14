// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 6）
// 示例说明：变通方法 2——双参数 setf(std::ios::hex, std::ios::basefield)，
//           会清除 basefield 组全部标志、只设置 hex。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   1b
// 备注：原 Example 6 是片段，这里包进 main() 并补 <iostream>。代码逐字抽取。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    // Turn on std::ios::hex as the only std::ios::basefield flag
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
