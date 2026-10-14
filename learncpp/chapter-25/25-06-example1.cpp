// ============================================================
// 来源小节：25.6 The virtual table（原 Example 1）
// 示例说明：静态类型 vs 动态类型。非虚 getName() 按静态类型 (Base) 解析；
//           虚 getNameVirtual() 按动态类型 (Derived) 解析。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-virtual-table/
// 预期输出：
//   base has static type Base
//   base has dynamic type Derived
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string_view>

class Base
{
public:
    virtual ~Base() = default;
    std::string_view getName() const { return "Base"; }              // not virtual
    virtual std::string_view getNameVirtual() const { return "Base"; } // virtual
};

class Derived : public Base
{
public:
    std::string_view getName() const { return "Derived"; }
    std::string_view getNameVirtual() const override { return "Derived"; }
};

int main()
{
    Derived derived{};
    Base& base{ derived };

    std::cout << "base has static type " << base.getName() << '\n';
    std::cout << "base has dynamic type " << base.getNameVirtual() << '\n';

    return 0;
}
