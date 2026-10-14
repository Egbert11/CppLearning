// ============================================================
// 来源小节：14.11 Default constructors and default arguments
// 示例说明：用户定义的默认构造函数。对这类非聚合类，值初始化 Foo foo{} 与
//           默认初始化 Foo foo2; 都会调用同一个默认构造函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/default-constructors-and-default-arguments/
// 备注：本节代码为按原文描述忠实重建（原文 Example 1 与 Example 2 合并）。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 1、2）---
class Foo
{
public:
    Foo() // default constructor
    {
        std::cout << "Foo default constructed\n";
    }
};

int main()
{
    Foo foo{};  // value initialization: calls Foo()
    Foo foo2;   // default initialization: also calls Foo()

    return 0;
}

// 预期输出：
// Foo default constructed
// Foo default constructed
