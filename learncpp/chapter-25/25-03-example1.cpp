// ============================================================
// 来源小节：25.3 The override and final specifiers, and covariant return types（原 Example 1）
// 示例说明：看起来像覆写、实际不是的两种情形 —— 参数类型不同（short vs int）、
//           多了 const。它们不构成覆写，于是通过 A& 调用仍执行 A 的版本。
// 原文链接：https://www.learncpp.com/cpp-tutorial/the-override-and-final-specifiers-and-covariant-return-types/
// 预期输出：
//   A
//   A
// 备注：本节代码为按原文描述重建。
// ============================================================
#include <iostream>
#include <string_view>

class A
{
public:
    virtual std::string_view getName1(int x) { return "A"; }
    virtual std::string_view getName2(int x) { return "A"; }
};

class B : public A
{
public:
    virtual std::string_view getName1(short x) { return "B"; }    // note: parameter is a short
    virtual std::string_view getName2(int x) const { return "B"; } // note: function is const
};

int main()
{
    B b{};
    A& rBase{ b };
    std::cout << rBase.getName1(1) << '\n';
    std::cout << rBase.getName2(2) << '\n';

    return 0;
}
