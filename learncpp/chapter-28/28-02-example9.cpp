// ============================================================
// 来源小节：28.2 Input with istream（原 Example 9）
// 示例说明：用非成员 std::getline(std::cin, str) 把一整行读进 std::string
//           （声明于 <string>，既不属于 ostream 也不属于 istream）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/input-with-istream/
// 预期：输入一行文本，原样输出。
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块）。
// ============================================================
#include <string>
#include <iostream>

int main()
{
    std::string strBuf{};
    std::getline(std::cin, strBuf);
    std::cout << strBuf << '\n';

    return 0;
}
