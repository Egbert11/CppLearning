// ============================================================
// 来源小节：28.x 本章测验（自拟；官方 28.x 尚未发布）
// 题目 2：用 std::stringstream 把 "12345 67.89" 解析为 int 与 double 并打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-28-summary-and-quiz/ （404）
// 预期输出：
//   12345 67.89
// 备注：官方暂无 28.x 总结/测验页，本文件为按本章内容自拟的测验解答。
// ============================================================
#include <sstream>
#include <iostream>

int main()
{
    std::stringstream os{};
    os << "12345 67.89";

    int nValue{};
    double dValue{};
    os >> nValue >> dValue;

    std::cout << nValue << ' ' << dValue << '\n';

    return 0;
}
