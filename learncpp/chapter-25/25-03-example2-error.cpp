// ============================================================
// 来源小节：25.3 The override and final specifiers, and covariant return types（原 Example 2）
// 示例说明：override 会强制编译器检查"这真的是覆写吗"。这里 B::getName1(short) 与
//           B::getName2(int) const 都不是覆写，因此各自产生一个编译错误；
//           只有 B::getName3(int) 是合法覆写。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/
// 预期错误（GCC，示意，两个 error）：
//   error: 'std::string_view B::getName1(short int)' marked 'override', but does not override
//   error: 'std::string_view B::getName2(int) const' marked 'override', but does not override
// 备注：本文件故意编译失败，勿修复。
// ============================================================
#include <string_view>

class A
{
public:
    virtual std::string_view getName1(int x) { return "A"; }
    virtual std::string_view getName2(int x) { return "A"; }
    virtual std::string_view getName3(int x) { return "A"; }
};

class B : public A
{
public:
    std::string_view getName1(short int x) override { return "B"; } // compile error, function is not an override
    std::string_view getName2(int x) const override { return "B"; } // compile error, function is not an override
    std::string_view getName3(int x) override { return "B"; }       // okay, function is an override of A::getName3(int)
};

int main()
{
    return 0;
}
