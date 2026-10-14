// ============================================================
// 来源小节：28.4 Stream classes for strings（原 Example 2）
// 示例说明：用 str(string) 函数直接把 stringstream 的缓冲区设为 "en garde!"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stream-classes-for-strings/
// 预期：缓冲区内容变为 "en garde!"。
// 备注：原 Example 2 是两行片段，这里包进 main() 并补 <sstream>/<iostream>；
//       为便于运行，末尾补上输出语句（原文未显示输出语句）。
// ============================================================
#include <sstream>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    std::stringstream os {};
    os.str("en garde!"); // set the stringstream buffer to "en garde!"
    // --- 原文示例片段结束 ---

    std::cout << os.str() << '\n'; // 为可运行而补
    return 0;
}
