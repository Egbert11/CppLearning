// ============================================================
// 来源小节：13.2 Unscoped enumerations
// 示例说明：每个枚举都是独立的类型（区别于 typedef/别名）。Pet 与 Color 是两个
//           不同的类型，不能把 Color 的枚举量用来初始化 Pet 变量。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
enum Pet
{
    cat,
    dog,
    pig,
    whale,
};

enum Color
{
    black,
    red,
    blue,
};

int main()
{
    [[maybe_unused]] Pet myPet { cat };
    [[maybe_unused]] Color myColor { red };

    // 下面这行是编译错误：black 属于 Color，不是 Pet 的枚举量。
    // 枚举是各自不同的类型，枚举量不能跨类型混用。
    [[maybe_unused]] Pet myPet2 { black };

    return 0;
}
