// 来源小节：11.4 Deleting functions
// 示例说明：用 = delete 删除 char/bool 重载，使这些调用在编译期被拒绝。
// 原文链接：https://www.learncpp.com/cpp-tutorial/deleting-functions/
//
// 编译：g++ -std=c++20 -Wall 11-04-example2-error.cpp -o a
//
// 本文件为"预期编译失败"示例（后缀 -error），请勿修复：
//   预期错误：
//     printInt('a')  -> 匹配到已删除的 printInt(char)，报 "use of deleted function"；
//     printInt(true) -> 匹配到已删除的 printInt(bool)，报 "use of deleted function"；
//     printInt(5.0)  -> 已删除的重载也参与解析，无候选无歧义最优，报 ambiguous 调用错误。
//
// 本节代码为按原文描述重建。

#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

void printInt(char) = delete; // calls to this function will halt compilation
void printInt(bool) = delete; // calls to this function will halt compilation

int main()
{
    printInt(97);   // okay

    printInt('a');  // compile error: function deleted
    printInt(true); // compile error: function deleted

    printInt(5.0);  // compile error: ambiguous match

    return 0;
}
