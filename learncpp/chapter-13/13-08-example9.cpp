// ============================================================
// 来源小节：13.8 Struct aggregate initialization
// 示例说明：聚合初始化按声明顺序把值映射到成员，因此"顺序很脆弱"：如果在结构
//           体中间插入一个成员，后面所有初始化器的含义都会悄悄错位，而编译器
//           可能不会报错。
// 原文链接：https://www.learncpp.com/cpp-tutorial/struct-aggregate-initialization/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
#include <iostream>

struct Foo
{
    int a {};
    int b {}; // 后来在中间插入了这个成员
    int c {};
};

int main()
{
    // 最初结构体只有 a 和 c 时：
    // Foo f { 1, 3 }; // f.a = 1, f.c = 3
    //
    // 在中间插入 int b 之后，同样的字面量含义就变了：
    Foo f { 1, 3 }; // now, f.a = 1, f.b = 3, f.c = 0

    std::cout << f.a << ' ' << f.b << ' ' << f.c << '\n';

    return 0;
}

// 预期输出：
// 1 3 0
