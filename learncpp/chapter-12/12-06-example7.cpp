// ============================================================
// 来源小节：12.6 Pass by const lvalue reference
// 示例说明：同一函数名的两种参数写法——const std::string& 与
//           std::string_view；原文指出大多数情况下优先用
//           std::string_view（按值）。这里仅作声明演示。
// 原文链接：https://www.learncpp.com/cpp-tutorial/pass-by-const-lvalue-reference/
// 备注：本节代码为按原文描述忠实重建（原 Example 6 之后的重载声明）。
//       两个 doSomething 未定义但未被调用，故可编译链接（无 link 错误）。
// ============================================================
#include <string>
#include <string_view>

// --- 原文示例片段 ---
void doSomething(const std::string&);
void doSomething(std::string_view); // prefer this in most cases
// --- 原文示例片段结束 ---

int main()
{
    return 0;
}
