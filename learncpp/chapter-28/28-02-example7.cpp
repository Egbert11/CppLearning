// ============================================================
// 来源小节：28.2 Input with istream（原 Example 7）
// 示例说明：与 Example 6 相同，但改用 getline()——getline() 会额外提取
//           （丢弃）分隔符（换行符），因此即使输入含换行也能按预期工作。
// 原文链接：https://www.learncpp.com/cpp-tutorial/input-with-istream/
// 预期：不再出现 Example 6 那种"第二次读空"的现象。
// 备注：代码取自原文 HTML 逐字抽取（<pre> 块），补上 #include <iostream>。
// ============================================================
#include <iostream>

int main()
{
    char strBuf[11]{};
    // Read up to 10 characters
    std::cin.getline(strBuf, 11);
    std::cout << strBuf << '\n';

    // Read up to 10 more characters
    std::cin.getline(strBuf, 11);
    std::cout << strBuf << '\n';
    return 0;
}
