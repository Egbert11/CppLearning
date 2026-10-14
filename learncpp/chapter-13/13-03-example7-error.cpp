// ============================================================
// 来源小节：13.3 Unscoped enumerator integral conversions
// 示例说明：整数默认不会隐式转换为无作用域枚举。无论花括号初始化还是赋值，
//           用整数初始化/赋值枚举变量都会编译失败。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/
// 备注：本节代码为按原文描述忠实重建。预期编译失败（两处）。
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
    Pet pet { 2 }; // compile error: integer value 2 won't implicitly convert to a Pet
    pet = 3;       // compile error: integer value 3 won't implicitly convert to a Pet

    return 0;
}
