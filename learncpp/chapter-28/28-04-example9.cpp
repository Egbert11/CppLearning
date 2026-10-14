// ============================================================
// 来源小节：28.4 Stream classes for strings（原 Example 9）
// 示例说明：清空缓冲区后调用 clear() 重置错误标志，再写入新内容。
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
    os.clear(); // reset error flags

    os << "World!";
    std::cout << os.str();

    return 0;
}
