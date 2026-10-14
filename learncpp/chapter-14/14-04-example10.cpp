// ============================================================
// 来源小节：14.4 Const class objects and const member functions
// 示例说明：const 限定符是函数签名的一部分，因此成员函数可以同时提供
//           const 与非 const 两个重载；非 const 对象选非 const 版本，
//           const 对象选 const 版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/const-class-objects-and-const-member-functions/
// 备注：本节代码为按原文描述忠实重建。这种重载较少见，通常用于返回值
//       的 const 性需要不同的场合。
// ============================================================
#include <iostream>

struct Something
{
    void print()
    {
        std::cout << "non-const\n";
    }

    void print() const
    {
        std::cout << "const\n";
    }
};

int main()
{
    Something s1{};
    s1.print(); // calls print()

    const Something s2{};
    s2.print(); // calls print() const

    return 0;
}

// 预期输出：
// non-const
// const
