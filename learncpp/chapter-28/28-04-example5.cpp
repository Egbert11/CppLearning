// ============================================================
// 来源小节：28.4 Stream classes for strings（原 Example 5）
// 示例说明：数字 → 字符串：把 int/double 写进流，再用 >> 以字符串取出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings/
// 预期输出：
//   12345 67.89
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补 <sstream>/<iostream>/<string>。
// ============================================================
#include <sstream>
#include <string>
#include <iostream>

int main()
{
    std::stringstream os {};

    constexpr int nValue { 12345 };
    constexpr double dValue { 67.89 };
    os << nValue << ' ' << dValue;

    std::string strValue1, strValue2;
    os >> strValue1 >> strValue2;

    std::cout << strValue1 << ' ' << strValue2 << '\n';

    return 0;
}
