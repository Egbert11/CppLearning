// ============================================================
// 来源小节：28.2 Input with istream（原 Example 3）
// 示例说明：用 while (std::cin >> ch) 逐字符读取——提取运算符会跳过空白
//           （空格、制表符、换行符），因此空白不会被输出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/input-with-istream/
// 预期：输入 "Hello my name is Alex"，输出 "HellomynameisAlex"
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补上 #include <iostream>。
// ============================================================
#include <iostream>

int main()
{
    char ch{};
    while (std::cin >> ch)
        std::cout << ch;

    return 0;
}
