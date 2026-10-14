// ============================================================
// 来源小节：14.16 Converting constructors and the explicit keyword
// 示例说明：与返回值相关的 explicit 构造函数——返回值的类型与返回类型不符时
//           会触发隐式转换，而隐式转换不能使用 explicit 构造函数。
//           本文件只保留合法的返回方式（对应原 Example 12 中 ok 的部分）。
// 原文链接：https://www.learncpp.com/cpp-tutorial/converting-constructors-and-the-explicit-keyword/
// 备注：本节代码为按原文描述忠实重建。非法返回方式见 14-16-example10-error.cpp。
// ============================================================
#include <iostream>

class Foo
{
public:
    explicit Foo()
    {
        std::cout << "Foo()\n";
    }

    explicit Foo(int x)
    {
        std::cout << "Foo(int)\n";
    }
};

// --- 原文示例片段（原 Example 12，ok 部分）---
Foo getFoo()
{
    // explicit Foo() cases
    return Foo{ };   // ok: explicitly construct a Foo

    // explicit Foo(int) cases
    // return Foo{ 5 }; // ok: explicitly construct a Foo
}
// --- 原文示例片段结束 ---

int main()
{
    getFoo();

    return 0;
}

// 预期输出：
// Foo()
