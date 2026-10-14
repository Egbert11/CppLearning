// ============================================================
// 来源小节：14.15 Class initialization and copy elision
// 示例说明：同样的六种初始化形式应用于类类型 Foo——编译器根据重载决议选择
//           默认构造函数、Foo(int) 或拷贝构造函数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/class-initialization-and-copy-elision/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

// --- 原文示例片段（原 Example 2）---
class Foo
{
public:
    Foo() // default constructor
    {
        std::cout << "Foo()\n";
    }

    Foo(int x) // normal constructor
    {
        std::cout << "Foo(int)\n";
    }

    Foo(const Foo& foo) // copy constructor
    {
        std::cout << "Foo(const Foo&)\n";
    }
};

int main()
{
    Foo f1;         // default initialization -> default constructor
    Foo f2{};       // value initialization -> default constructor

    Foo f3 = 3;     // copy initialization -> Foo(int) (non-explicit)
    Foo f4(4);      // direct initialization -> Foo(int)
    Foo f5{ 5 };    // direct list initialization -> Foo(int)
    Foo f6 = { 6 }; // copy list initialization -> Foo(int)

    Foo f7 = f5;    // copy initialization -> copy constructor
    Foo f8(f5);     // direct initialization -> copy constructor
    Foo f9{ f5 };   // direct list initialization -> copy constructor
    Foo f10 = { f5 };// copy list initialization -> copy constructor

    // 原文这些变量未使用；此处标记以避免 unused 警告。
    (void)f1; (void)f2; (void)f3; (void)f4; (void)f5;
    (void)f6; (void)f7; (void)f8; (void)f9; (void)f10;

    return 0;
}
// --- 原文示例片段结束 ---

// 预期输出：
// Foo()
// Foo()
// Foo(int)
// Foo(int)
// Foo(int)
// Foo(int)
// Foo(const Foo&)
// Foo(const Foo&)
// Foo(const Foo&)
// Foo(const Foo&)
