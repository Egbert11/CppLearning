// ============================================================
// 来源小节：28.4 Stream classes for strings（原 Example 3）
// 示例说明：用 os.str() 取出整个缓冲区内容并打印。
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
    os << "12345 67.89\n";
    std::cout << os.str();

    return 0;
}
