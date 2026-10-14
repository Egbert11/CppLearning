// ============================================================
// 来源小节：28.4 Stream classes for strings（原 Example 7）
// 示例说明：用空 C 风格字符串 os.str("") 清空缓冲区后再写入。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings/
// 预期输出：
//   World!
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补 <sstream>/<iostream>。
// ============================================================
#include <sstream>
#include <iostream>

int main()
{
    std::stringstream os {};
    os << "Hello ";

    os.str(""); // erase the buffer

    os << "World!";
    std::cout << os.str();

    return 0;
}
