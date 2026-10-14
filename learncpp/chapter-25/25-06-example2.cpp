// ============================================================
// 来源小节：25.6 The virtual table（原 Example 2-7 的可运行重建）
// 示例说明：编译器为每个多态类建立一张虚表（virtual table），并在对象里放一个隐藏指针
//           __vptr 指向它。通过基类指针调用虚函数时，程序沿 __vptr 找到对应虚表、
//           取出"最派生可调用版本"的函数指针再跳转。
//           这里 Base/D1/D2 三个类各有一张虚表：D1 的 function1 指向 D1::function1，
//           function2 仍指向 Base::function2；D2 相反。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-virtual-table/
// 预期输出：
//   D1::function1()
//   Base::function2()
//   Base::function1()
// 备注：原文的虚表/__vptr 图示无法直接编译，本文件按描述重建为可运行示例以展示解析结果。
// ============================================================
#include <iostream>

class Base
{
public:
    virtual ~Base() = default;
    virtual void function1() { std::cout << "Base::function1()\n"; }
    virtual void function2() { std::cout << "Base::function2()\n"; }
};

class D1 : public Base
{
public:
    void function1() override { std::cout << "D1::function1()\n"; }
};

class D2 : public Base
{
public:
    void function2() override { std::cout << "D2::function2()\n"; }
};

int main()
{
    D1 d1{};
    Base* dPtr{ &d1 };

    // d1.__vptr points to D1's virtual table:
    //   function1 entry -> D1::function1()   (most-derived version)
    //   function2 entry -> Base::function2() (not overridden by D1)
    dPtr->function1(); // resolves to D1::function1()
    dPtr->function2(); // resolves to Base::function2()

    Base b{};
    Base* bPtr{ &b };

    // b.__vptr points to Base's virtual table, so Base::function1() runs
    bPtr->function1(); // resolves to Base::function1()

    return 0;
}
