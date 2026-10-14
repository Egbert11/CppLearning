// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：更多临时对象——std::string { "Hello" } 创建用文本初始化的临时
//           std::string；std::string {} 用值初始化创建临时 std::string。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>
#include <string>

int main()
{
    // --- 原文示例片段（原 Example 9）---
    std::string { "Hello" }; // create a temporary std::string initialized with "Hello"
    std::string {};          // create a temporary std::string using value initialization
    // --- 原文示例片段结束 ---

    // 上面两句各自创建并随即销毁一个临时对象（语句本身无副作用）。
    std::cout << std::string { "Hello" }.size() << '\n'; // 5

    return 0;
}
