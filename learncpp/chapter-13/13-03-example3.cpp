// ============================================================
// 来源小节：13.3 Unscoped enumerator integral conversions
// 示例说明：枚举量可以显式赋任意整数值（正数、负数），也可重复；未显式赋值的
//           枚举量仍取"前一个 + 1"。注意 horse 与 giraffe 取同一值 5，
//           此时它们彼此"不再可区分"，虽然合法但不推荐。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
enum Animal
{
    cat = -3,    // values can be negative
    dog,         // -2
    pig,         // -1
    horse = 5,
    giraffe = 5, // shares same value as horse
    chicken,     // 6
};

int main()
{
    [[maybe_unused]] Animal a { horse };
    return 0;
}
