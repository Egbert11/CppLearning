// ============================================================
// 来源小节：28.2 Input with istream（原 Example 2）
// 示例说明：用操纵器 std::setw(10) 限制从流中读取的最大字符数，
//           避免 Example 1 中的缓冲区溢出问题（只读入 9 个字符，留出结束符）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/input-with-istream/
// 预期：输入多于 9 个字符时，只取前 9 个；剩余字符留在流中供下次提取。
// 备注：原 Example 2 是片段，这里包进 main() 以便独立编译。
//       代码取自原文 HTML 逐字抽取（<pre> 块）。
// ============================================================
#include <iomanip>
#include <iostream>

int main()
{
    // --- 原文示例片段 ---
    char buf[10]{};
    std::cin >> std::setw(10) >> buf;
    // --- 原文示例片段结束 ---

    std::cout << buf << '\n';
    return 0;
}
