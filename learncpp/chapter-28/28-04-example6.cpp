// ============================================================
// 来源小节：28.4 Stream classes for strings（原 Example 6）
// 示例说明：字符串 → 数字：把数字文本插入流，再提取为 int/double。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings/
// 预期输出：
//   12345 67.89
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补 <sstream>/<iostream>。
// ============================================================
#include <sstream>
#include <iostream>

int main()
{
    std::stringstream os {};
    os << "12345 67.89"; // insert a string of numbers into the stream
    int nValue {};
    double dValue {};

    os >> nValue >> dValue;

    std::cout << nValue << ' ' << dValue << '\n';

    return 0;
}
