// ============================================================
// 来源小节：25.4 Virtual destructors, virtual assignment, and overriding virtualization（原 Example 4+5）
// 示例说明：忽略虚函数机制 —— 用作用域解析运算符 Base::getName() 强制调用基类版本，
//           而不是虚解析得到的 Derived::getName()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization/
// 预期输出：
//   Base
// 备注：本节代码为按原文描述重建（原文中类定义与 main 分为两块）。
// ============================================================
#include <iostream>
#include <string_view>

class Base
{
public:
    virtual ~Base() = default;
    virtual std::string_view getName() const { return "Base"; }
};

class Derived : public Base
{
public:
    std::string_view getName() const override { return "Derived"; }
};

int main()
{
    Derived derived{};
    const Base& base{ derived };

    // Calls Base::getName() instead of the virtualized Derived::getName()
    std::cout << base.Base::getName() << '\n';

    return 0;
}
