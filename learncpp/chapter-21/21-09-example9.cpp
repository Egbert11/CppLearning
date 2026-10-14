// 来源小节：21.9 Overloading the subscript operator
// 示例说明：operator[] 的参数类型不受限制，可以是 std::string_view 等任意类型，
//           这适合实现“用单词作键”的映射式访问。
// 原文链接：https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/
// 说明：本节代码为按原文描述重建。原文示例的类名即为 Stupid。
// 预期输出：Hello, world!

#include <iostream>
#include <string_view>

class Stupid
{
public:
    void operator[] (std::string_view index)
    {
        std::cout << index;
    }
};

int main()
{
    // --- 原文示例片段 ---
    Stupid stupid{};
    stupid["Hello, world!"]; // prints Hello, world!
    // --- 原文示例片段结束 ---

    std::cout << '\n';

    return 0;
}
