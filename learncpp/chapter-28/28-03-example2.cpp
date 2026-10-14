// ============================================================
// 来源小节：28.3 Output with ostream and ios（原 Example 2）
// 示例说明：用按位或一次打开 showpos 与 uppercase 两个标志。
// 原文链接：https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/
// 预期输出：
//   +1.23457E+06
// 备注：原 Example 2 是片段，这里包进 main() 并补 <iostream>。代码逐字抽取。
// ============================================================
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::cout.setf(std::ios::showpos | std::ios::uppercase); // turn on the std::ios::showpos and std::ios::uppercase flag
    std::cout << 1234567.89f << '\n';
    // --- 原文示例片段结束 ---

    return 0;
}
