// ============================================================
// 来源小节：28.2 Input with istream（原 Example 4）
// 示例说明：用 while (std::cin.get(ch)) 逐字符读取——get() 不会丢弃空白，
//           因此与 Example 3 相比空白被原样保留。
// 原文链接：https://www.learncpp.com/cpp-tutorial/input-with-istream/
// 预期：输入 "Hello my name is Alex"，输出 "Hello my name is Alex"
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补上 #include <iostream>。
// ============================================================
#include <iostream>

int main()
{
    char ch{};
    while (std::cin.get(ch))
        std::cout << ch;

    return 0;
}
