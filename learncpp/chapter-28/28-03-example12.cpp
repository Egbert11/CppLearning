// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 12）
// 示例说明：在 fixed / scientific 模式下 setprecision 控制的是“小数位数”。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   123.456
//   123.4560
//   123.45600
//   123.456000
//   123.4560000
//
//   1.235e+002
//   1.2346e+002
//   1.23456e+002
//   1.234560e+002
//   1.2345600e+002
// 备注：原 Example 12 是片段，这里包进 main() 并补
//       <iostream> 与 <iomanip>（setprecision 声明于 <iomanip>）。代码逐字抽取。
// ============================================================
#include <iomanip>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout << std::fixed << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';

    std::cout << std::scientific << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
