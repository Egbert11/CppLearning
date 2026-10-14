// ============================================================
// 来源小节：23.7 std::initializer_list
// 示例说明：Foo 只有 Foo(int, int) 构造函数；花括号调用
//           Foo f1{ 1, 2 } 匹配该非列表构造函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期输出：
//   Foo(int, int) called
// 备注：本节代码为按原文描述重建（原 Example 10）。
// ============================================================
#include <iostream>

class Foo
{
public:
    Foo(int, int)
    {
        std::cout << "Foo(int, int) called\n";
    }
};

int main()
{
    Foo f1{ 1, 2 }; // calls Foo(int, int)

    return 0;
}
