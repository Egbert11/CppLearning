// ============================================================
// 来源小节：14.8 The benefits of data hiding (encapsulation)
// 示例说明：std::string_view 提供 length() 接口，内部实现（如何取长度）对用户不可见。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-benefits-of-data-hiding-encapsulation/
// 备注：本节代码为按原文描述忠实重建。原文未给出输出。
// ============================================================
#include <iostream>
#include <string_view>

// --- 原文示例片段（原 Example 1）---
int main()
{
    std::string_view sv{ "Hello, world!" };
    std::cout << sv.length();

    return 0;
}

// 预期输出：
// 13
