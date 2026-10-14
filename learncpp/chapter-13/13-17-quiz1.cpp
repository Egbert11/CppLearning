// ============================================================
// 来源小节：13.y Using a language reference（本仓库文件号 13-17）
// 示例说明：测验 1 解答——预测 std::string::erase(4, 11) 的输出。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-a-language-reference/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>

int main()
{
    // --- 原文示例片段（原 Example 4）---
    std::string str{ "The rice is cooking" };

    str.erase(4, 11); // erase 11 characters starting at index 4: "rice is coo"

    std::cout << str << '\n';

    return 0;
}

// 预期输出：
// The king
//
// 解释：erase 的该重载从 index 起删除 min(count, size() - index) 个字符，
//       此处 min(11, 19 - 4) = 11，即删除下标 4..14 的 "rice is coo"。
