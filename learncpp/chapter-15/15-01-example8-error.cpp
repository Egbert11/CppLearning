// ============================================================
// 来源小节：15.1 The hidden "this" pointer and member function chaining
// 示例说明：在 const 对象上调用非 const 成员函数会失败。对于 const
//           成员函数，this 是"指向 const 值的 const 指针"；对非 const
//           成员函数而言 this 指向非 const 值。在 const 对象上调用
//           非 const 成员函数需要丢弃 const，编译器不允许隐式这样做。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/
// 预期错误（不要修复）：
//   error: passing 'const Something' as 'this' argument discards qualifiers [-fpermissive]
//   （MSVC 类似：error C2662: cannot convert 'this' pointer from 'const Something' to 'Something &'）
// 备注：这是演示预期编译失败的示例文件，请勿修复。
// ============================================================
#include <iostream>

struct Something
{
    int value{};

    int getValue() { return value; } // 注意：非 const 成员函数
};

int main()
{
    const Something s{}; // const 对象
    std::cout << s.getValue() << '\n'; // 错误：在 const 对象上调用非 const 成员函数

    return 0;
}
