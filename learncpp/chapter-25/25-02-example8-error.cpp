// ============================================================
// 来源小节：25.2 Virtual functions and polymorphism（原 Example 8）
// 示例说明：虚函数的返回类型必须与基类版本一致，否则不算覆写。
//           这里 Base::getValue() 返回 int，而 Derived::getValue() 返回 double，
//           返回类型不匹配 —— 预期编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/virtual-functions/
// 预期错误（GCC，示意）：
//   error: conflicting return type specified for 'virtual double Derived::getValue() const'
//   error:   overriding 'virtual int Base::getValue() const'
// 备注：本文件故意编译失败，勿修复；该示例仅用于演示"非匹配覆写"。
// ============================================================

class Base
{
public:
    virtual ~Base() = default;
    virtual int getValue() const { return 5; }
};

class Derived : public Base
{
public:
    virtual double getValue() const override { return 6.78; } // note: return type is double, not int
};

int main()
{
    return 0;
}
