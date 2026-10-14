// ============================================================
// 来源小节：24.9 Multiple inheritance（原 Example 3）
// 示例说明：奇异的递归模板模式 CRTP——派生类把自己作为模板类型参数传给混入基类：
//           class Derived : public Mixin<Derived>。混入于是可以把它持有的 this
//           静态转换为 T*，从而触达派生类的成员。原文只给出模式骨架，这里补全为
//           一个可编译、可运行的最小示例。
// 原文链接：https://www.learncpp.com/cpp-tutorial/multiple-inheritance/
// 预期输出：
//   Mixin says: Derived::bar()
// 备注：本节代码为按原文描述重建并以最小可运行示例补全。
// ============================================================
#include <iostream>

// The Curiously Recurring Template Pattern (CRTP)
template <class T>
class Mixin
{
public:
    // Mixin<T> can use template type parameter T to access members of Derived
    // via (static_cast<T*>(this))
    void foo()
    {
        static_cast<T*>(this)->bar();
    }
};

class Derived : public Mixin<Derived>
{
public:
    void bar()
    {
        std::cout << "Derived::bar()\n";
    }
};

int main()
{
    Derived d;
    std::cout << "Mixin says: ";
    d.foo();

    return 0;
}
