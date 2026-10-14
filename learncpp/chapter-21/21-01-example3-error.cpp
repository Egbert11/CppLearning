// 来源小节：21.1 Introduction to operator overloading
// 示例说明：对程序自定义类型 Mystring 使用 +，编译器找不到匹配的 operator+
//           → 编译失败。这演示了"类类型必须自己重载运算符"这一点。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/
// 预期错误：编译失败。因为既没有为 Mystring 重载 operator+，也没有重载 operator<<，
//           编译器会报类似：
//             error: no match for 'operator+' (operand types are 'Mystring' and 'Mystring')
//             error: no match for 'operator<<' (operand types are 'std::ostream' ... and 'Mystring')
// 备注：预期编译失败（-error），请勿修复。原文本例为片段，这里用了最小的 Mystring
//       （只有存储与构造函数）以便如实地让 string1 + string2 编译失败。原文 Example 3。

#include <iostream>
#include <string>
#include <string_view>

// 最小化的 Mystring：只有存储与构造函数，没有为它重载任何运算符
class Mystring
{
private:
    std::string m_string;

public:
    Mystring(std::string_view s) : m_string{ s } { }
};

int main()
{
    // --- 原文示例片段 ---
    Mystring string1 { "Hello, " };
    Mystring string2 { "World!" };
    std::cout << string1 + string2 << '\n'; // 没有为 Mystring 重载 operator+
    // --- 原文示例片段结束 ---

    return 0;
}
