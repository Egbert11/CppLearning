// ============================================================
// 来源小节：25.3 The override and final specifiers, and covariant return types（原 Example 4）
// 示例说明：final 标记在类上，禁止被继承。这里 B 被声明为 final，
//           于是 C 继承 B 产生编译错误。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/
// 预期错误（GCC，示意）：
//   error: cannot derive from 'final' base 'B' in derived type 'C'
// 备注：本文件故意编译失败，勿修复。
// ============================================================
#include <string_view>

class A
{
public:
    virtual ~A() = default;
    virtual std::string_view getName() const { return "A"; }
};

class B final : public A // note use of final specifier here
{
public:
    std::string_view getName() const override { return "B"; }
};

class C : public B // compile error: cannot inherit from final class
{
public:
    std::string_view getName() const override { return "C"; }
};

int main()
{
    return 0;
}
