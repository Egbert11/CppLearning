// ============================================================
// 来源小节：13.3 Unscoped enumerator integral conversions
// 示例说明：C++17 的"用整数列表初始化枚举"只对花括号形式放行。直接初始化
//           （括号）、拷贝初始化（=）以及赋值都不允许用整数。
// 原文链接：https://www.learncpp.com/cpp-tutorial/unscoped-enumerator-integral-conversions/
// 备注：本节代码为按原文描述忠实重建。预期编译失败（三处）。原文示例中
//       pet1 的花括号初始化合法，已在 13-03-example9.cpp 单独演示。
// ============================================================
enum Pet : int // we've specified a base
{
    cat,   // assigned 0
    dog,   // assigned 1
    pig,   // assigned 2
    whale, // assigned 3
};

int main()
{
    Pet pet1 { 2 }; // ok: can brace initialize unscoped enumeration with specified base with integer (C++17)
    Pet pet2 (2);   // compile error: cannot direct initialize with integer
    Pet pet3 = 2;   // compile error: cannot copy initialize with integer

    pet1 = 3;       // compile error: cannot assign with integer

    return 0;
}
