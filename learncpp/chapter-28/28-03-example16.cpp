// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 16）
// 示例说明：用 fill('*') 设置填充字符（一旦设置会跨多个语句生效），
//           再看 setw(10) 配合 left/right/internal 的填充效果。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出（原文逐字；宽度 10、"-12345" 占 6 字符，故填充 4 个 '*'）：
//   -12345
//   ****-12345
//   -12345****
//   ****-12345
//   -****12345
// 备注：原 Example 16 是片段，这里包进 main() 并补
//       <iostream> 与 <iomanip>。代码逐字抽取。
// ============================================================
#include <iomanip>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout.fill('*');
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified
    // --- 原文示例片段结束 ---

    return 0;
}
