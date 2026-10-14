// ============================================================
// 来源小节：28.4 Stream classes for strings（原 Example 1）
// 示例说明：用插入运算符 << 把 "en garde!\n" 放进 stringstream 的缓冲区。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings/
// 预期：缓冲区内容变为 "en garde!\n"。
// 备注：原 Example 1 是两行片段，这里包进 main() 并补 <sstream>/<iostream>；
//       为便于运行，末尾补上 std::cout << os.str();（原文未显示输出语句）。
// ============================================================
#include <sstream>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::stringstream os {};
    os << "en garde!\n"; // insert "en garde!" into the stringstream
    // --- 原文示例片段结束 ---

    std::cout << os.str(); // 为可运行而补：输出缓冲区内容
    return 0;
}
