// 来源小节：5.x Chapter 5 summary and quiz（测验第 2 题）
// 题目：下面这个程序存在三个问题，请找出并修复。本文件按原文原样保留（含三个问题），
//       用于对照找出缺陷；它可以通过编译，但行为不正确。
// 原文链接：https://www.learncpp.com/cpp-tutorial/chapter-5-summary-and-quiz/
//
// ※※※ 说明 ※※※
// 本节示例为按原文描述重建。
// 三个问题：
//   1) std::uint8_t 实际是字符类型：读入 "18" 只会提取字符 '1'（ASCII 49），
//      把用户当成年纪 49 —— 应改为普通 int，并去掉 <cstdint>。
//   2) 魔术数字 16 —— 应改为 constexpr 变量。
//   3) '.\n' 是多字符字面量，输出不正确 —— 应改为双引号的 ".\n"。
//
// 原文给出的示例输出（未修复时对照用）：
//   输入 6  -> Allowed to drive a car in Texas: No
//   输入 19 -> Allowed to drive a car in Texas: Yes

#include <cstdint>
#include <iostream>

int main()
{
    std::cout << "How old are you?\n";

    std::uint8_t age{};
    std::cin >> age;

    std::cout << "Allowed to drive a car in Texas: ";

    if (age >= 16)
        std::cout << "Yes";
    else
        std::cout << "No";

    std::cout << '.\n'; // 问题 3：应为 ".\n"

    return 0;
}
