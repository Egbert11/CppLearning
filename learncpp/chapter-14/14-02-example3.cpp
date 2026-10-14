// ============================================================
// 来源小节：14.2 Introduction to classes
// 示例说明：Fraction 用注释记录类不变量（denominator 永不为 0），并用
//           默认成员初始化器把它们默认置为合法值。
// 原文链接：https://www.learncpp.com/cpp-tutorial/introduction-to-classes/
// 备注：本节代码为按原文描述忠实重建。原文仅给出类型定义，此处补一个
//       空的 main() 使其可独立编译。
// ============================================================
struct Fraction
{
    int numerator { 0 };
    int denominator { 1 }; // class invariant: should never be 0
};

int main()
{
    [[maybe_unused]] Fraction f{};
    return 0;
}
