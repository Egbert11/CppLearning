// ============================================================
// 来源小节：23.7 std::initializer_list
// 示例说明：给 Foo 添加 Foo(std::initializer_list<int>) 后，同样的
//           调用 Foo f1{ 1, 2 } 改而匹配列表构造函数——这就是"添加
//           列表构造函数可能悄悄改变现有代码行为"的示例。
// 原文链接：https://www.learncpp.com/cpp-tutorial/stdinitializer_list/
// 预期输出：
//   Foo(std::initializer_list<int>) called
// 备注：本节代码为按原文描述重建（原 Example 11）。
// ============================================================
#include <iostream>
#include <initializer_list>

class Foo
{
public:
    Foo(int, int)
    {
        std::cout << "Foo(int, int) called\n";
    }

    Foo(std::initializer_list<int>)
    {
        std::cout << "Foo(std::initializer_list<int>) called\n";
    }
};

int main()
{
    Foo f1{ 1, 2 }; // now calls Foo(std::initializer_list<int>)

    return 0;
}
