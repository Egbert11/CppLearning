// ============================================================
// 来源小节：13.y Using a language reference（本仓库文件号 13-17）
// 示例说明：测验 2 解答——用一次 str.replace 把 "red" 换成 "blue"。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-a-language-reference/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>

int main()
{
    // --- 原文示例片段（原 Example 5、6）---
    std::string str{ "I saw a red car yesterday." };

    str.replace(8, 3, "blue"); // replace 3 characters starting at index 8 ("red") with "blue"

    std::cout << str << '\n'; // I saw a blue car yesterday.

    return 0;
}

// 预期输出：
// I saw a blue car yesterday.
