// ============================================================
// 来源小节：28.2 Input with istream（原 Example 5）
// 示例说明：get() 的字符串重载 std::cin.get(strBuf, 11) 最多读 10 个字符
//           （第 11 个位置留给结束符 '\0'），其余字符留在流中。
// 原文链接：https://www.learncpp.com/cpp-tutorial/input-with-istream/
// 预期：输入 "Hello my name is Alex"，输出 "Hello my n"
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补上 #include <iostream>。
// ============================================================
#include <iostream>

int main()
{
    char strBuf[11]{};
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';

    return 0;
}
