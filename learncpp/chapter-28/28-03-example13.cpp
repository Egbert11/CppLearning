// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 13）
// 示例说明：在没有 fixed / scientific 时，setprecision 控制的是“有效数字位数”。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   123
//   123.5
//   123.46
//   123.456
//   123.456
// 备注：原 Example 13 是片段，这里包进 main() 并补
//       <iostream> 与 <iomanip>。代码逐字抽取。
// ============================================================
#include <iomanip>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
