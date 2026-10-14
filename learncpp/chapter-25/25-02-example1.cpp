// ============================================================
// 来源小节：25.2 Virtual functions and polymorphism（原 Example 1）
// 示例说明：非虚函数。Base& 绑定 Derived 对象，但 rBase.getName() 解析到 Base::getName()。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-functions/
// 预期输出：
//   rBase is a Base
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string_view>

class Base
{
public:
    std::string_view getName() const { return "Base"; } // note: not virtual
};

class Derived : public Base
{
public:
    std::string_view getName() const { return "Derived"; }
};

int main()
{
    Derived derived {};
    const Base& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}
