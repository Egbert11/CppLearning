// ============================================================
// 来源小节：14.13 Temporary class objects
// 示例说明：无参形式——Foo(); 创建值初始化的临时对象（等价于 Foo {}）；
//           而 Foo bar{}; 定义变量 bar；Foo bar(); 却声明一个函数（最令人困惑的解析）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/temporary-class-objects/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

class Foo
{
public:
    Foo()
    {
        std::cout << "Foo default constructed\n";
    }
};

int main()
{
    // --- 原文示例片段（原 Example 11）---
    Foo();     // temporary Foo, value-initialized (identical to Foo {})
    Foo bar{}; // defines a variable bar, value-initialized
    // Foo bar(); // declares a function bar, taking no parameters and returning Foo
    // --- 原文示例片段结束 ---

    (void)bar;

    return 0;
}
