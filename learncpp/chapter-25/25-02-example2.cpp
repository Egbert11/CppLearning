// ============================================================
// 来源小节：25.2 Virtual functions and polymorphism（原 Example 2）
// 示例说明：把 getName() 声明为 virtual 后，Base& 绑定 Derived 对象时解析到 Derived::getName()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-functions/
// 预期输出：
//   rBase is a Derived
// 备注：本节代码为按原文描述重建。为消除"有虚函数却无虚析构"的编译器警告，Base 加了虚析构。
// ============================================================
#include <iostream>
#include <string_view>

class Base
{
public:
    virtual ~Base() = default;                              // virtual destructor (see lesson 25.4)
    virtual std::string_view getName() const { return "Base"; } // note: virtual
};

class Derived : public Base
{
public:
    std::string_view getName() const override { return "Derived"; }
};

int main()
{
    Derived derived {};
    const Base& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}
