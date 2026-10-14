// 来源小节：4.4 Signed integers
// 示例说明：整数除法会丢弃小数部分（而非四舍五入）—— 8 / 5 数学上是 1.6，截断为 1。
//           原文输出：1
// 原文链接：https://www.learncpp.com/cpp-tutorial/signed-integers/
//
// 编译：g++ -std=c++20 -Wall 4-04-example5.cpp -o a

#include <iostream>

int main()
{
    std::cout << 8 / 5 << '\n';
    return 0;
}
