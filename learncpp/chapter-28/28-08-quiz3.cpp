// ============================================================
// 来源小节：28.x 本章测验（自拟；官方 28.x 尚未发布）
// 题目 3：把 27 按十六/八/十进制打印，并把 123.456 用 fixed + setprecision(3) 打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-28-summary-and-quiz/ （404）
// 预期输出：
//   1b
//   33
//   27
//   123.456
// 备注：官方暂无 28.x 总结/测验页，本文件为按本章内容自拟的测验解答。
// ============================================================
#include <iomanip>
#include <iostream>

int main()
{
    std::cout << std::hex << 27 << '\n'; // 十六进制
    std::cout << std::oct << 27 << '\n'; // 八进制
    std::cout << std::dec << 27 << '\n'; // 十进制

    std::cout << std::fixed << std::setprecision(3) << 123.456 << '\n';

    return 0;
}
