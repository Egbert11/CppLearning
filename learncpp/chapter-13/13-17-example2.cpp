// ============================================================
// 来源小节：13.y Using a language reference（本仓库文件号 13-17）
// 示例说明：用 std::lock_guard lock(mx) 作为 if 的 init-statement（教程认为最清晰的一例）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/using-a-language-reference/
// 备注：本节代码为按原文描述忠实重建。单个线程下运行即可，演示 init-statement 语法。
// ============================================================
#include <iostream>
#include <mutex>

std::mutex mx;
bool shared_flag = true; // guarded by mx

void unsafe_ping()
{
    std::cout << "ping\n";
}

int main()
{
    // --- 原文示例片段（原 Example 3）---
    if (std::lock_guard lock(mx); shared_flag) // define lock (a variable), then a semicolon, then the condition
    {
        unsafe_ping();
        shared_flag = false;
    }

    return 0;
}

// 预期输出：
// ping
