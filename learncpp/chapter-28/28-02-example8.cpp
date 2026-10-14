// ============================================================
// 来源小节：28.2 Input with istream（原 Example 8）
// 示例说明：用 gcount() 报告上一次 getline() 提取了多少个字符。
//           注意 gcount() 把被丢弃的分隔符也算在内。
// 原文链接：https://www.learncpp.com/cpp-tutorial/input-with-istream/
// 预期：例如输入 "Hello!" 回车，输出 "Hello!" 以及 "7 characters were read"
//       （6 个字符 + 被丢弃的换行符 = 7）。
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补上 #include <iostream>。
// ============================================================
#include <iostream>

int main()
{
    char strBuf[100]{};
    std::cin.getline(strBuf, 100);
    std::cout << strBuf << '\n';
    std::cout << std::cin.gcount() << " characters were read" << '\n';

    return 0;
}
