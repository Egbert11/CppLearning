// ============================================================
// 来源小节：28.4 Stream classes for strings（原 Example 8）
// 示例说明：改用空 std::string 对象 os.str(std::string{}) 清空缓冲区。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings/
// 预期输出：
//   World!
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补 <sstream>/<iostream>/<string>。
// ============================================================
#include <sstream>
#include <string>
#include <iostream>

int main()
{
    std::stringstream os {};
    os << "Hello ";

    os.str(std::string{}); // erase the buffer

    os << "World!";
    std::cout << os.str();

    return 0;
}
