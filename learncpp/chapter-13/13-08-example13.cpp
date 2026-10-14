// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：聚合体可以用同类型的另一个对象来初始化（走的是拷贝/直接/直接列表
//           初始化，而不是聚合初始化）；从函数返回值初始化同类型对象时很常见。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Foo
{
    int a {};
    int b {};
    int c {};
};

void printFoo(const Foo& f)
{
    std::cout << f.a << ' ' << f.b << ' ' << f.c << '\n';
}

int main()
{
    Foo foo { 1, 2, 3 };

    Foo x = foo;  // copy initialize
    Foo y(foo);   // direct initialize
    Foo z {foo};  // direct-list initialize

    printFoo(x);
    printFoo(y);
    printFoo(z);

    return 0;
}

// 预期输出：
// 1 2 3
// 1 2 3
// 1 2 3
