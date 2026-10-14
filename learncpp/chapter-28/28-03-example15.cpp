// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 15）
// 示例说明：字段宽度 setw(10) 与 left / right / internal 对齐方式。
//           internal 让符号左对齐、数值右对齐。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出（本机实际见文末）：
//   -12345
//       -12345
//   -12345
//       -12345
//   -    12345
// 备注：原 Example 15 是片段，这里包进 main() 并补
//       <iostream> 与 <iomanip>（setw 声明于 <iomanip>）。代码逐字抽取。
// ============================================================
#include <iomanip>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified
    // --- 原文示例片段结束 ---

    return 0;
}
