// ============================================================
// 来源小节：28.x 本章测验（自拟；官方 28.x 尚未发布）
// 题目 1：读入一行可能含空格的文本并原样回显。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-28-summary-and-quiz/ （404）
// 预期：输入一行（含空格）后原样输出该行。
// 备注：官方暂无 28.x 总结/测验页，本文件为按本章内容自拟的测验解答。
// ============================================================
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a line of text: ";
    std::string line{};
    std::getline(std::cin, line);
    std::cout << line << '\n';

    return 0;
}
