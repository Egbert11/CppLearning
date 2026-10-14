// ============================================================
// 来源小节：25.3 The override and final specifiers, and covariant return types（原 Example 3）
// 示例说明：final 标记在虚函数上，禁止后续再覆写。这里 B::getName() 被标记 final，
//           于是 C 试图覆写它产生编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/
// 预期错误（GCC，示意）：
//   error: virtual function 'virtual std::string_view C::getName() const'
//   error: overriding final function 'virtual std::string_view B::getName() const'
// 备注：本文件故意编译失败，勿修复。
// ============================================================
#include <string_view>

class A
{
public:
    virtual std::string_view getName() const { return "A"; }
};

class B : public A
{
public:
    std::string_view getName() const override final { return "B"; } // okay, B::getName() overrides A::getName()
};

class C : public B
{
public:
    std::string_view getName() const override { return "C"; } // compile error, B::getName() is final
};

int main()
{
    return 0;
}
