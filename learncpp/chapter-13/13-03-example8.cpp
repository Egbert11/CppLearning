// ============================================================
// 来源小节：13.3 Unscoped enumerator integral conversions
// 示例说明：整数转枚举的绕过办法是 static_cast。只要目标值落在底层类型可表示的
//           范围内（且该值确实由某个枚举量表示）都是安全的；超出范围则是 UB。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/
// 备注：本节代码为按原文描述忠实重建。
// ============================================================
enum Pet // no specified base
{
    cat,   // assigned 0
    dog,   // assigned 1
    pig,   // assigned 2
    whale, // assigned 3
};

int main()
{
    Pet pet { static_cast<Pet>(2) }; // convert integer 2 to a Pet
    pet = static_cast<Pet>(3);       // our pig evolved into a whale!

    (void)pet; // 原文未使用 pet，这里仅为消除 -Wunused-but-set-variable 警告
    return 0;
}
