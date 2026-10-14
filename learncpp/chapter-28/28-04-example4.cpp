// ============================================================
// 来源小节：28.4 Stream classes for strings（原 Example 4）
// 示例说明：用 >> 连续取出两个值（按空白分隔），以短横连接打印。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings/
// 预期输出：
//   12345 - 67.89
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补 <sstream>/<iostream>/<string>。
// ============================================================
#include <sstream>
#include <string>
#include <iostream>

int main()
{
    std::stringstream os {};
    os << "12345 67.89"; // insert a string of numbers into the stream

    std::string strValue {};
    os >> strValue;

    std::string strValue2 {};
    os >> strValue2;

    // print the numbers separated by a dash
    std::cout << strValue << " - " << strValue2 << '\n';

    return 0;
}
